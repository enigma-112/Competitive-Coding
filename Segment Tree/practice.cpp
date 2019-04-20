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
    
    if(start>end){
        return;
    }
    if(start==end){
        
        tree[treeindex].maximum=value;
        tree[treeindex].s_max=INT_MIN;
        return;
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

node query_Tree(node* tree,int start,int end,int treeindex,int left,int right){
    
    node ans;
    ans.maximum=-1;
    ans.s_max=-1;
    
    // range is outside
    if(start>right||end<left){
       return ans; 
    }
    
    // range is completely inside
    if(start>=left&&end<=right){
        return (tree[treeindex]);
        
    }
    
    //range is partially overlapping
    
    int mid = start  + (end-start)/2;
    node ans_left = query_Tree(tree,start,mid,2*treeindex,left,right);
    node ans_right = query_Tree(tree,mid+1,end,2*treeindex+1,left,right);
    
    
    ans.maximum=max(ans_left.maximum,ans_right.maximum);
    ans.s_max=min(max(ans_left.maximum,ans_right.s_max),max(ans_left.s_max,ans_right.maximum))    ;
    return ans;
    
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
    

// cout<<"Befor building Tree :"<<endl;
// for(int i=0;i<=4*n;i++){

//     cout<<tree[i].maximum<<" "<<tree[i].s_max<<endl;
// }




   // 1.building Segment Tree
    build_Tree(arr,tree,0,n-1,1);

    // cout<<"After building Tree :"<<endl;

    //     for(int i=0;i<=4*n;i++){

    //     cout<<tree[i].maximum<<" "<<tree[i].s_max<<endl;
    // }
        
    //     }


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
           node ans= query_Tree(tree,0,n-1,1,x-1,y-1);
           cout<<ans.maximum+ans.s_max<<endl;
           
        }
        
    }
}











