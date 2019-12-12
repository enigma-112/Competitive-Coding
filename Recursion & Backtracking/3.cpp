#include<bits/stdc++.h>
using namespace std;

int main(){


int t;
cin>>t;
while(t--){
int n;

	cin>>n;

	int arr[n]={0};
	for(int i=0;i<=n-1;i++){
		cin>>arr[i];
	}

	sort(arr,arr+n);	
	int abc=0;
	
	for(int i=n-2;i>=1;i--){
		int x=arr[i];
		
		if((x!=0) && (x&(x-1))==0){
		
				if(((x&arr[i+1])!=0 )   && (arr[i-1]==x-1)){
					
					int temp=arr[i-1];
					arr[i-1]=arr[i];
					arr[i]=temp;

				}

		}
		
		
	}
	long long int ans=0;
	int x=0;
	for(int i=n-1;i>=0;i--){
		 
			 x=x|arr[i];
			ans+=x;
	}
	cout<<ans<<endl;
	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;


}
}