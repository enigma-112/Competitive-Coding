#include<bits/stdc++.h>

using namespace std;

int main(){

	int n;

	cin>>n;

	int x =n-1;
	int odd;
	int extra;
	int ans;
	int prev =1;
	if(n==1){
		cout<<1;
	}

	else{

		for(int i= 1;i<=x;i++){

			odd = 2*i -1;
			extra = 4*odd;
			int ans1 = extra/2 +2;
			ans = prev + ans1;
			prev =ans;
		}

		cout<<ans;
	}


}