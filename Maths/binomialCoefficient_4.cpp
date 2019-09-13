// Iterative Solution of C(n,k) .ie C(n,k) = (n*(n-1)*....*(n-k+1)) / k!
// Time Complexity = O(k)
// Space Complexity = O(1)

#include<bits/stdc++.h>
using namespace std;
int bc4(int n,int k){

	if(k>n-k){
		k=n-k;
	}

	int result =1;

	for(int i=0;i<=k-1;i++){

		result *= (n-i);
		result /= (i+1);

	}
	return result;
}
int main(){

	int n,k;
	cin>>n>>k;
	int ans = bc4(n,k);
	cout<<"Value of C("<<n<<","<<k<<")"<<" = "<<ans<<endl;
}