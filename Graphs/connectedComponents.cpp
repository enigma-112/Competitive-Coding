#include<iostream>
#include<vector>
#include<unordered_set>
#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> * g,int n,bool * visited, unordered_set<int> &s2,int i){
	visited[i]=true;
	s2.insert(i);
	for(auto x:g[i]){
		if(visited[i]==false){
			dfs(g,n,visited,s2,x);
		}
	}



}

void findComponents(vector<int> * g,int n, unordered_set<unordered_set<int>> &s1){
	bool * visited = new bool [n];
	for(int i=0;i<=n-1;i++){
		visited[i]=false;
	}

	for(int i=0;i<=n-1;i++){
		if(visited[i]==false){
			unordered_set<int> s2;			
			dfs(g,n,visited,s2,i);
			s1.insert(s2);
		}
	}


}

int main(){

	int n,e;
	cin>>n>>e;
	
	vector<int> *g = new vector<int> [n]; // g is a graph represented as adjacency list -- array of vectors
	for(int i=0;i<=n-1;i++){
		int v1,v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}

	unordered_set<unordered_set<int>> s1;
	findComponents(g,n,s1);

	// for(auto x: s1){
	// 	for(auto y: x){
	// 		cout<<y<<" ";
	// 	}
	// 	cout<<endl;

	// }

}