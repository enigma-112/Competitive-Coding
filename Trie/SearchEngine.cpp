#include <bits/stdc++.h>
using namespace std;


class trieNode{
    public:
    	int weight;
    	trieNode ** children;

    trieNode(){
    	children = new trieNode *[26];
    	for(int i=0;i<=25;i++){
    		children[i]=NULL;
    	}
    	weight = 0;
    }
    
    
};

void insert(trieNode * root, string s,int weight){


	if(s.empty()){
		return;
	}
	trieNode * child;
	int index = s[0]-'a';


	
	if(root->children[index]){
		child = root->children[index];
	}
	else{

		child= new trieNode ();
		root->children[index] = child;
	}


	if(root->weight<weight){
		root->weight = weight;
	}
	insert(child,s.substr(1),weight);

}

int best_string_weight(trieNode* root, string s){

	int best_weight = -1;
	trieNode * currNode =root;
	for(int i=0;i<=s.length()-1;i++){
		int index = s[i]- 'a';

		trieNode * child = currNode->children[index];
		if(child){
			currNode = child;
			best_weight = child->weight;

		}
		else{
			return -1;
		}


			}

		return best_weight;
}

int main()
{

	int n,q;
	cin>>n>>q;
	trieNode * root = new trieNode();
	for(int i=0;i<=n-1;i++){
		string s;
		int weight;
		cin>>s>>weight;
		insert(root,s,weight);
	}

	for(int i=0;i<=q-1;i++){
		string s;
		cin>>s;
		cout<<best_string_weight(root,s)<<endl;
	}
    return 0;
}
