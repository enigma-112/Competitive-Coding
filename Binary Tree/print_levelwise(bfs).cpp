#include<bits/stdc++.h>
using namespace std;

class BTnode{		// Binary Tree node class
public:
	int data;
	BTnode* left;
	BTnode* right;
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

// Levelorder traversal in same line (also known as BFS(Breadth First Search))
void print_levelwise(BTnode * root){
	if(root==NULL){
		return;
	}

	
	queue<BTnode*> q;
	q.push(root);

	while(!q.empty()){
		
		BTnode * x = q.front();
		cout<<x->data<<" ";
		q.pop();

		if(x->left!=NULL){
			q.push(x->left);
		}
		if(x->right!=NULL){
			q.push(x->right);
		}

	}
	

}

// Levelorder traversal in different lines
void levelorder_different_lines(BTnode* root){
if(root==NULL){
	return ;
}

queue<BTnode*> q;
q.push(root);
q.push(NULL);
while(!q.empty()){
	BTnode* x=q.front();
	q.pop();
	if(x!=NULL){
		cout<<x->data<<" ";
		if(x->left!=NULL){
			q.push(x->left);
		}
		if(x->right!=NULL){
			q.push(x->right);
		}
	}
	if(x==NULL&&(!q.empty())){
		cout<<endl;
		q.push(NULL);
	}
}




}

int count_nodes(BTnode * root){
	if(root==NULL){
		return 0;
	}

	return (1+count_nodes(root->left)+count_nodes(root->right));

}

int height(BTnode* root){
	if(root==NULL){
		return 0;
	}

	return (1+max(height(root->left),height(root->right)));



}

// Finding a node
bool isPresent(BTnode* root,int item){
	if(root==NULL){
		return false;
	}

	if(root->data==item){
		return true;
	}

	return (isPresent(root->left,item)||isPresent(root->right,item));



}

int main(){
	BTnode * root = takeinput_levelwise();
	print_levelwise(root);
	cout<<endl<<count_nodes(root)<<endl;
	cout<<height(root)<<endl;
	levelorder_different_lines(root);

	if(isPresent(root,9)){
		cout<<endl<<9<<" is Present !!"<<endl;
	}
	else{
		cout<<9<<" is not Present !!"<<endl;
	}
}