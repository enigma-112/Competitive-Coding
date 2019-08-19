#include<bits/stdc++.h>
using namespace std;


void dfsHelper(vector<int> g1[],int n,int x,bool * visited){
	visited[x]=true;

	cout<<x<<" ";

	for(auto i: g1[x]){
		if(visited[i]==false){
			dfsHelper(g1,n,i,visited);
		}
	}
}
void dfs(vector<int> g1[],int n,int x){

	bool * visited = new bool[n];

	for(int i=0;i<=n-1;i++){
		visited[i] =false;
	}

	dfsHelper(g1,n,x,visited);

}
int main(){

	int n,e;
	cin>>n>>e;

	vector<int> g1[n];
	for(int i=0;i<=e-1;i++){
		int s,e;
		cin>>s>>e;
		g1[s].push_back(e);
		g1[e].push_back(s);
	}

	dfs(g1,n,1);


}