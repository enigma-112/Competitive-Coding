#include<bits/stdc++.h>
using namespace std;

typedef  long long int ll;
int main() {
	   
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	   
	int t;
	cin>>t;
	
	while(t--){
	    int  n;
	    cin>>n;
	    
	    ll arr[n];
	    for(int i=0;i<=n-1;i++){
	        cin>>arr[i];
	    }
	    
	    stack<ll> st1;
	    
	    ll max_area =0;
	    int i=0;
	    for(;i<=n-1;){
	        if(st1.empty()==true || arr[i]>=arr[st1.top()]){
	            st1.push(i);
	            i++;
	        }
	        
	        else{
	            ll curr_area=0;
	            ll height = arr[st1.top()];
	            st1.pop();
	            if(st1.empty()==true){
	                curr_area = height*i;
	                 if(curr_area>max_area){
	                max_area=curr_area;
	            }
	            }
	            else{
	            ll width = i-st1.top()-1;
	             curr_area = height*width;
	            
	            if(curr_area>max_area){
	                max_area=curr_area;
	            }
	            
	         }
	       }
	    }
	    
	    while(st1.empty()!=true){
	        
	            ll curr_area=0;
	            ll height = arr[st1.top()];
	            st1.pop();
	            if(st1.empty()==true){
	                curr_area = height*i;
	                 if(curr_area>max_area){
	                max_area=curr_area;
	            }
	            }
	            else{
	            ll width = i-st1.top()-1;
	             curr_area = height*width;
	            
	            if(curr_area>max_area){
	                max_area=curr_area;
	            }
	            
	         }
	   }
	    
	    cout<<max_area<<endl;
	    
	}
	return 0;
}