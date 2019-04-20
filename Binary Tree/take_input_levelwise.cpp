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

BTnode* takeinput_levelwise(){
int data;
cin>>data;
if(data==-1){
	return NULL;
}
BTnode * root=new BTnode(data);

queue<BTnode *> q;

q.push(root);
while(!q.empty()){
	BTnode * node = q.front();
	q.pop();

	int leftchild;
	cin>>leftchild;

	if(leftchild!=-1){
		BTnode* x=new BTnode(leftchild);
		node->left=x;
		q.push(x);
	}

	int rightchild;
	cin>>rightchild;
	if(rightchild!=-1){
		BTnode * y=new BTnode(rightchild);
		node->right=y;
		q.push(y);
	}


}

return root;
}
void print_tree(BTnode* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	print_tree(root->left);
	print_tree(root->right);
}

int main(){
	BTnode * root = takeinput_levelwise();
	print_tree(root);
	return 0;
}