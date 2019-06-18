// to find a to the power n in log(n) time


#include<bits/stdc++.h>
using namespace std;


int find_ans(int a,int n){

	if(n==0){
		return 1;
	}

	int result = find_ans(a,n/2);
	int ans;

	if(n&1){

		ans = a*result *result;

	}
	else{
		ans = result*result;


	}

	return ans;

}


int main(){

	int a,n;
	cin>>a>>n;

	cout<<find_ans(a,n)<<endl;
}