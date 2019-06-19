#include<bits/stdc++.h>
using namespace std;

class trieNode{
public:
	trieNode * left;
	trieNode * right;
};
// Inserting integers in trie
void insert(int n,trieNode * head){

	trieNode * currNode = head;
	for(int i=31;i>=0;i--){
		int bit = (n>>i) & 1;

		if(bit == 0){
			if(!currNode->left){
				currNode->left = new trieNode();
			}
			
			currNode = currNode->left;			
		}

		else{
			if(!currNode->right){
				currNode->right = new trieNode();
			}
			
			currNode=currNode->right;		
		}
	}
}

int find_MaxXorPairSum(trieNode * head, int *arr,int n){

		int max_xor = INT_MIN;

		for(int i=0;i<=n-1;i++){

			trieNode * currNode = head;
			int curr_element = arr[i];
			int curr_xor = 0;
			for(int j=31;j>=0;j--){

					int bit = (curr_element>>j) & 1;

					if(bit==0){
						if(currNode->right){
							//curr_xor=curr_xor | (1<<j);
							curr_xor += pow(2,j);
							currNode=currNode->right;
						}
						else{
							currNode = currNode->left;

						}
					}
					else{

						if(currNode->left){
							curr_xor += pow(2,j);
							currNode = currNode->left;
						}
						else{
							//curr_element = curr_element | (1<<j);
							currNode = currNode->right;
						}
					}


			}
			if(curr_xor>max_xor){
				max_xor = curr_xor;
			}
		}

		return max_xor;

}

int main(){

	trieNode * head  = new trieNode();

	int arr[]= {3, 10, 5, 25, 2, 8};
	for(int i=0;i<=5;i++){
		insert(arr[i],head);
	}


	cout<<find_MaxXorPairSum(head,arr,6)<<endl;



}
