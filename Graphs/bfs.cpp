#include<bits/stdc++.h>
using namespace std;



void bfs(vector<int>* g1,int n,int start){

	  
   queue<int> q1;
   bool * visited = new bool[n];

   for(int i=0;i<=n-1;i++){
		visited[i]=false;
	}

	q1.push(start);

	visited[start]=true;

	while(!q1.empty()){

		int x = q1.front();
		cout<<x<<" ";
		q1.pop();

		for(auto i: g1[x]){
            
            if(visited[i]==false){
			q1.push(i);
			visited[i]=true;
            }
		}
	}


}
int main(){

	int n,e;
	cin>>n>>e;

	vector<int> *g1=new vector<int>[n];

	for(int i=0;i<=n-1;i++){

		int s,e;
		cin>>s>>e;

		g1[s].push_back(e);
		g1[e].push_back(s);
	}

	bfs(g1,n,0);

}