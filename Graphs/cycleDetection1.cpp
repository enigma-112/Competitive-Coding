// cycle detection in a directed graph using dfs and an extra array (inStack)

#include<bits/stdc++.h>
using namespace std;


bool helper(vector<int> * g1, int n,int x, bool * visited, bool * instack){
  
	visited[x] = true;
	instack[x]= true;

	for(auto i : g1[x]){

		if(visited[i]==false ){

			bool ans =helper(g1,n,i,visited,instack);
			if(ans==true){
		    	return true;
			}
		}
		else{
		    if(instack[i]==true)
			return true;
		}
		
		}
	

	instack[x]=false;

	return false;
}
bool isCyclic(int n, vector<int> g1[])
{
    
    bool * visited = new bool [n];
	bool * instack = new bool [n];

	for(int i=0;i<=n-1;i++){
	    visited[i]=false;
	    instack[i] = false;
	}
	for(int i=0;i<=n-1;i++){

		if(visited[i]==false){
				bool ans = helper(g1,n,i,visited,instack);
				    
				if(ans==true){
				    return true;
				}
	}
	}

	return false;
    
    
}
int main(){

	int n,e;
	cin>>n>>e;

	vector<int> * g1 = new vector<int>[n];

	for(int i=0;i<=e-1;i++){
		int s,e;
		cin>>s>>e;
		g1[s].push_back(e);
	}

	cout<<findCycle(g1,n)<<endl;


}