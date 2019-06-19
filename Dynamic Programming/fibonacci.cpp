// to find nth fibonacci no.

#include<bits/stdc++.h>
using namespace std;


int find_ans3(int n){


int * dp = new int [1000];

dp[0] =0;
dp[1]= 1;

for(int i = 2;i<=n;i++){
	dp[i]=dp[i-1]+dp[i-2];
}

return dp[n];

}

int find_ans2(int n,int dp[]){

	if(n==0||n==1){
		return n;
	}

	if(dp[n]!=-1){
		return dp[n];
	}


	int smallans = find_ans2(n-1,dp)+find_ans2(n-2,dp);

	dp[n]= smallans;

	return dp[n];

}
int find_ans1(int n){

	if(n==0||n==1){
		return n;
	}

	int smallans = find_ans1(n-1)+find_ans1(n-2);

	return smallans;

}
int main(){
	int n;
	cin>>n;

	// method 1 : Normal Recursion

	int ans1 = find_ans1(n);
	cout<<ans1<<endl;

	//method 2 : Memozation -> top-down DP


	int dp[1000];
	for(int i=0;i<=999;i++){
		dp[i]=-1;
	}
	int ans2 = find_ans2(n,dp);
	cout<<ans2<<endl;

	//method 3 : DP -> bottom-up DP

	int ans3 = find_ans3(n);
	cout<<ans3<<endl;
}