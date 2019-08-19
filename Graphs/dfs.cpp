#include<bits/stdc++.h>
using namespace std;

class graph{

	map<int,list<int>> g;
public:

	graph(){

	}
	void addEdge(int u,int v,bool bidir = true){

		g[u].push_back(v);
		if(bidir == true){
			g[v].push_back(u);
		}
	}


	void dfsHelper(int x,map<int,bool> &visited){
		visited[x]=true;
		cout<<x<<" ";

		for(auto i: g[x]){
			if(visited[i]==false){
				dfsHelper(i,visited);
			}
		}

	}
	void dfs(int x){

		map<int,bool> visited;

		dfsHelper(x,visited);

	}

};

int main(){

	int n,e;
	cin>>n>>e;
	graph g1;
	for(int i=0;i<=e-1;i++){
		int s,e;
		cin>>s>>e;
		g1.addEdge(s,e);

	}

	g1.dfs(1);


}