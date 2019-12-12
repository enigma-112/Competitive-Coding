// Brute force --> Generating all the different arrangements of parenthesis and checking which one is valid.
// T --> O(n*(2^2n))

#include<bits/stdc++.h>
using namespace std;


bool valid(string s){

	int left=0;
	for(int i=0;i<=int(s.length())-1;i++){

		if(s[i]=='('){
			left++;
		}
		else if(s[i]==')'){
			if(left==0){
				return false;
			}
			else{
				left--;
			}
		}

	}
	if(left!=0){
		return false;
	}
	return true;
}
void find_ans(string s,int n){
	
	if(s.length()==n){
		if(valid(s)){
			cout<<s<<endl;
		}
		return;
	}


		 find_ans(s+'(',n);
		 find_ans(s+')',n);

	

}
int main(){
	
		int n;
		cin>>n;
		find_ans("",2*n); // Length of string will be 2*n

}