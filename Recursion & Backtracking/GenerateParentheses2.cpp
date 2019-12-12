// With Constraint --> T --> Asymptotic Upper Bound of catalan no. ==  O(4^n / n^(3/2))


#include<iostream>
#include<string>
using namespace std;

void find_ans(string s, int n, int left, int right){
	
	if(s.length()==2*n){
		cout<<s<<endl;
		return;
	}
	
	if(left < n){
		find_ans(s + '(', n,left+1,right); 
	}
	if(right <left){
		find_ans(s + ')', n,left,right+1);
	}

}
int main(){
	int n;
	cin>>n;
	find_ans("", n, 0, 0);

}
