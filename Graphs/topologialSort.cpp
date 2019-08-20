// Topological Sort using dfs

#include<bits/stdc++.h>
using namespace std;


void helper(vector<int> * g1,int n,int start,bool * visited, stack<int> & s1){

	visited[start]=true;

	for(auto i: g1[start]){
		if(visited[i]==false){
		helper(g1,n,i,visited,s1);
		}
	}

	
	s1.push(start);
}

void topologicalSort(vector<int> * g1,int n){

	bool * visited = new bool [n];

	for(int i=0;i<=n-1;i++){
		visited[i]=false;
	}

	stack<int> s1;

	for(int i=0;i<=n-1;i++){
		if(visited[i]==false){
			helper(g1,n,i,visited,s1);
		}
	}

	//Printing the topological Sorted values

	for(int i=0;i<=n-1;i++){
		cout<<s1.top()<<" ";
		s1.pop();
	}
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

	topologicalSort(g1,n);
}