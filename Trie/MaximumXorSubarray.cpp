#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    trieNode *left;
    trieNode *right;
};


void insert(trieNode * head,int n){
    
    trieNode *currNode = head;
    for(int i=31;i>=0;i--){
        int bit = (n>>i) & 1;
        
        if(bit==1){
            if(!currNode->right){
                currNode->right=new trieNode ();
            }
            currNode=currNode->right;
        }
        else{
            if(!currNode->left){
                currNode->left = new trieNode();
            }
            currNode= currNode->left;            
        } 
    }     
}

int find_MaxXorSubarray(trieNode * head,int n){

	int max_xor=0;
	trieNode *currNode = head;
	for(int i=31;i>=0;i--){

		int bit = (n>>i) & 1;
		if(bit==1){
			if(currNode->left){
				max_xor += pow(2,i);
				currNode = currNode->left; 
			}
			else{
				currNode = currNode->right;
			}
		}
		else{

			if(currNode->right){
				max_xor += pow(2,i);
				currNode = currNode->right;
			}
			else{
				currNode = currNode->left;
			}

		}
	}
	return max_xor;



}
int main() {

	int n;
	cin>>n;
	int *arr = new int[n];
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
	trieNode * head  = new trieNode();


	int max_xor = INT_MIN;
	int curr_xor =0;
	int flag=0;
	for(int i=0;i<=n-1;i++){
        
		int curr_max=0;
		int curr_element=arr[i];
		curr_xor = curr_xor ^ curr_element;
		if(flag==0){
			insert(head,arr[0]);
            flag++;
		}

		curr_max=find_MaxXorSubarray(head,curr_xor)	;
		max_xor=max(curr_xor,max(max_xor,curr_max));
		insert(head,curr_xor);


	}

	

	cout<<max_xor<<endl;


}