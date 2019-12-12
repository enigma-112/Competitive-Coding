#include<iostream>
using namespace std;
typedef long long int ll;
#define mod 1000000007


ll find_ans(int n,int m){

	if(n<m){
		return 1;
	}
	if(n==m){
		return 2;
	}

	ll ans1= find_ans(n-1,m)%mod;
	ll ans2 = find_ans(n-m,m)%mod;


	return (ans1+ans2)%mod	;



}

int main(){

	int t;
	cin>>t;
	while(t--){

		int n,m;
		cin>>n>>m;

		ll ans=0;

		ans = find_ans(n,m);
		cout<<ans<<endl;

	}

}