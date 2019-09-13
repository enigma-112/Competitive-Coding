// Recursive implementation of Binomial Coefficient i.e C(n,k)
#include<bits/stdc++.h>
using namespace std;


int bc(int n,int k){

	if(k==0||k==n){
		return 1;
	}

	int smallans1 = bc(n-1,k-1);
	int smallans2 = bc(n-1,k);

	int ans = smallans1+smallans2;

	return ans;

}
int main(){

	int n,k;
	cin>>n>>k;

	int ans = bc(n,k);
	cout<<"Value of C("<<n<<","<<k<<")"<<" = "<<ans<<endl;
}