#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	while(t--){

		string str;
		cin>>str;
		sort(str.begin(),str.end());
		int flag=0;
		for(int i=1;i<=n-1;i++){
			if(str[i]!=str[i]+1)
				flag=1;
			cout<<"NO"<<endl;
			break;
		}
		if(flag==1){
			cout<<"YES"<<endl;
		}

	}
}