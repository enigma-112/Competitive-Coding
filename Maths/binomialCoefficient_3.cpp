// Space optimised DP implementation of Binomial Coefficient i.e C(n,k)
// Time Complexity = O(n*k)
// Space Complexity = O(k)

#include <bits/stdc++.h>
using namespace std;


int bc3(int n,int k){

	int arr[k+1];
	for(int i=0;i<=k;i++){
		arr[i]=0;
	}
	arr[0]=1;

	for(int i=1;i<=n ;i++){

		for(int j=min(i,k);j>=1;j--){
			arr[j]=arr[j]+arr[j-1];
		}
	}
return arr[k];
}
int main(){

	int n,k;
	cin>>n>>k;
	int ans = bc3(n,k);
	cout<<"Value of C("<<n<<","<<k<<")"<<" = "<<ans<<endl;
}