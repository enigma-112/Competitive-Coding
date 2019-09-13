// DP implementation of Binomial Coefficient i.e C(n,k)
// Time Complexity = O(n*k)
// Space Complexity = O(n*k)

#include<bits/stdc++.h>
using namespace std;

int bc2(int n,int k){

	int dp[n+1][k+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=min(i,k);j++){
			if(j==0||i==j){
				dp[i][j]=1;
			}
			else{
				dp[i][j]=dp[i-1][j-1]+dp[i-1][j];

			}

		}
	}

	return dp[n][k];
}
int main(){

	int n,k;
	cin>>n>>k;
	int ans = bc2(n,k);
	cout<<"Value of C("<<n<<","<<k<<")"<<" = "<<ans<<endl;
}