#include<bits/stdc++.h>
using namespace std;

int main(){


	int t;
	cin>>t;
	while(t--){

			int n;
			cin>>n;
			unordered_map<string,int> m1;
			unordered_map<string,int> m2;

			int ans=0;
			for(int i=0;i<=n-1;i++){
				string s;
				int x;
				
				cin>>s;
				cin>>x;

				if(x==0){
					m2[s]++;
				}
				else{
					m1[s]++;
				}

			}
			for(auto i: m1){
				string t = i.first;
				if(m2.count(t)==1){
					if(m1[t]>=m2[t]){
						ans+=m1[t];
					}
					else{
						ans+= m2[t];
					}
				}
				else{
					ans+=m1[t];
				}
			}
			for(auto i: m2){
				 string t = i.first;
				 if(m1.count(t)==0){
				 	ans+=m2[t];
				 }
			}

			cout<<ans<<endl;
			

	}

}


