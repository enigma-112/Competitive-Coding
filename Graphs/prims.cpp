#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

class compare{
	public:
		bool operator()(pii x,pii y){
			return x.second >y.second;
		}
};


void prims(vector<pii> * g1,int n){

	bool * visited = new bool[n];
	for(int i=0;i<=n-1;i++){
		visited[i]=false;
	}

	int minCost = 0;

	priority_queue<pii,vector<pii>,compare> pq1; //  pq1 is min priority queue where first element is the vertex and second element is it's weight 
							 // and it is sorted based on it's weights

	pq1.push(make_pair(0,0));

	while(!pq1.empty()){

		pii x  = pq1.top();
		pq1.pop();
		if(visited[x.first]==true){
			continue;
		}

		visited[x.first]=true;
		minCost += x.second;

		for(auto i : g1[x.first]){

				if(visited[i.first]==false){
					pq1.push(i);
				}
		}
	}

	cout<<endl<<minCost<<endl;


}
int main(){

	int n,e;
	cin>>n>>e;

	vector<pii> * g1 = new vector<pii> [n];

	for(int i=0;i<=e-1;i++){
		int s,e,w;

		cin>>s>>e>>w;
		g1[s].push_back(make_pair(e,w));
		g1[e].push_back(make_pair(s,w));
	}

	prims(g1,n);




}