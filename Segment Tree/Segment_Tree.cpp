//Program for implementation of Segment Tree

#include<bits/stdc++.h>
using namespace std;


//1. Building Segment Tree

void build_Tree(int *arr,int* tree,int start,int end,int treenode){

	if(start==end){
		tree[treenode]=arr[start];
		return;
	}


	int mid =(start+end)/2;

	build_Tree(arr,tree,start,mid,2*treenode);
	build_Tree(arr,tree,mid+1,end,2*treenode+1);

	tree[treenode]= tree[2*treenode]+tree[2*treenode+1];
	return ;
}

// 2. Updating Segment Tree

void update_Tree(int *arr,int *tree,int start,int end,int treenode,int index,int value){

	if(start==end){
		arr[start]=value;
		tree[treenode]=value;
		return;
	}

	int mid=(start+end)/2;

	if(index<=mid){
		update_Tree(arr,tree,start,mid,2*treenode,index,value);
	}
	else{
		update_Tree(arr,tree,mid+1,end,2*treenode +1,index,value);
	}

	tree[treenode]=tree[2*treenode]+tree[2*treenode +1];
	return;
}

int main(){

	int n;
	cout<<"Enter the size of Array and then elements of array"<<endl;
	cin>>n;
	int *arr=new int [n];	// arr[] is the input array
	for(int i=0;i<=n-1;i++){
		cin>>arr[i];
	}

	int *tree = new int [4*n]; // tree is the segment tree

	for(int i=0;i<=4*n-1;i++){
		tree[i]=0;
	}

	// 1. Building Segment Tree
	build_Tree(arr,tree,0,n-1,1);
	
	// Printing the Segment Tree
	for(int i=0;i<=4*n-1;i++){
		cout<<tree[i]<<" ";
	}


	cout<<endl<<"Enter the index as well as the new value of the index which is to be updated: "<<endl;
	int index,value;
	cin>>index>>value;
	// 2. Update Segment Tree
	update_Tree(arr,tree,0,n-1,1,index,value);

	// Printing the Updated Tree
	for(int i=1;i<=4*n-1;i++){
		cout<<tree[i]<<" ";
	}




}