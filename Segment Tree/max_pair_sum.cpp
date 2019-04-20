#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int maximum;
    int s_max;
    
};



// 1.building Segment Tree
void build_Tree(int *arr,node *tree,int start,int end,int treeindex){
    
    if(start==end){
        tree[treeindex].maximum=arr[start];
        tree[treeindex].s_max=INT_MIN;
        return;
    }
    
    int mid = start +(end-start)/2;
    
    build_Tree(arr,tree,start,mid,2*treeindex);
    build_Tree(arr,tree,mid+1,end,2*treeindex+1);
    
    node left= tree[2*treeindex];
    node right= tree[2*treeindex+1];
    
    tree[treeindex].maximum=max(left.maximum,right.maximum);
    tree[treeindex].s_max=min(max(left.maximum,right.s_max),max(right.maximum,left.s_max));
    return ;
    
    
}
// 2.udating Segment Tree
void update_Tree(int *arr,node *tree,int start,int end,int treeindex,int index,int value){
    
    if(start==end){
        arr[start]=value;
        tree[treeindex].maximum=value;
        tree[treeindex].s_max=INT_MIN;
    }
    
    int mid=start+(end-start)/2;
    if(index<=mid){
        update_Tree(arr,tree,start,mid,2*treeindex,index,value);
    }
    else{
        update_Tree(arr,tree,mid+1,end,2*treeindex+1,index,value);
    }
    node left= tree[2*treeindex];
    node right= tree[2*treeindex+1];
    
    tree[treeindex].maximum=max(left.maximum,right.maximum);
    tree[treeindex].s_max=min(max(left.maximum,right.s_max),max(right.maximum,left.s_max));
    return ;
    
}
// 3. Doing query on tree

node *query_Tree(node* tree,int start,int end,int treeindex,int left,int right){
    
    // range is outside
    if(left>end||right<start){
        node *x = new node;
        x->maximum=0;
        x->s_max=0;
        return x; 
    }
    
    // range is completely inside
    if(start>=left&&end<=right){
        node * ans=new node;
        ans->maximum=tree[treeindex].maximum;
        ans->s_max=tree[treeindex].s_max;
        return ans;
        
    }
    
    //range is partially overlapping
    
    int mid = start  + (end-start)/2;
    node *ans1 = query_Tree(tree,start,mid,2*treeindex,left,right);
    node *ans2 = query_Tree(tree,mid+1,end,2*treeindex+1,left,right);
    
    
    int max1=max(ans1->maximum,ans2->maximum);
    int s_max1=min(max(ans1->maximum,ans2->s_max),max(ans2->maximum,ans1->s_max));

    node * ans= new node;
    ans->maximum=max1;
    ans->s_max=s_max1;
    return ans;
    //    if((ans1->maximum+ans1->s_max)>(ans2->maximum+ans2->s_max))
    //     return ans1;
    // else
    //     return ans2;
    
    
    
}
int main() {

    	// Write your code here


    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    
    node* tree=new node[4*n+1];
    
   // 1.building Segment Tree
    build_Tree(arr,tree,0,n-1,1);
    
    int q;
    cin>>q;
    while(q--){
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        if(ch=='U'){
            // 2. Updating Segment Tree
            update_Tree(arr,tree,0,n-1,1,x-1,y);
        }
        else{
            node  *ans=query_Tree(tree,0,n-1,1,x-1,y-1);
            cout<<(ans->maximum+ans->s_max);
            cout<<endl;
        }
        
    }













}