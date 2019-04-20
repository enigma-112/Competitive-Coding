#include<bits/stdc++.h>
using namespace std;

class BTnode{

public:
	int data;
	BTnode * left;
	BTnode * right;

BTnode(int d){
	data=d;
	left=NULL;
	right=NULL;
}

~BTnode(){
	delete left;
	delete right;
}
};
BTnode * takeinput_recursive(){
	int data;
	cin>>data;
	if(data==-1){
		return NULL;
	}

	BTnode * root = new BTnode(data);
	BTnode * leftsubtree = takeinput_recursive();
	BTnode * rightsubtree = takeinput_recursive();

	root->left=leftsubtree;
	root->right=rightsubtree;
	return root;

}
void print_tree(BTnode * root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	print_tree(root->left);
	print_tree(root->right);

}
int main(){

	BTnode* root=takeinput_recursive();
	print_tree(root);
	return 0;



}