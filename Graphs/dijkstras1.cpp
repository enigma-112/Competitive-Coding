// Dijkstra's algorithm using priority queue

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;


class compare{
	public:
		bool operator()(pii &p1,pii &p2){

			return p1.second > p2.second;
		}

};

void dijkstra(vector<pii> *g1,int n,int start){

	bool * visited = new bool [n];
	int * dist = new int [n];
	int * parent = new int [n];

	for(int i=0;i<=n-1;i++){
		dist[i]=INT_MAX;
		visited[i]=false;
	}

	priority_queue<pii, vector<pii> ,compare > pq1; // first element is vertex(v) and second element is it's weight(w) 
																	   // & pq1 is min priority queue based on it's weight
	pq1.push(make_pair(start,0));

	parent[0]=-1;
	dist[0]=0;

	while(!pq1.empty()){

		pii x = pq1.top();
		pq1.pop();

		int cv = x.first;
		int cw = x.second;

		if(visited[cv]==true){
			continue;
		}

		visited[cv] = true;

		for(pii y : g1[cv]){

			if(visited[y.first] == false && ( dist[cv] + y.second < dist[y.first] ) ){

				dist[y.first] = dist[cv] + y.second;
				parent[y.first] = cv;
				pq1.push(make_pair(y.first,dist[y.first]));


			}


		}
		


	}


	// Printing the distances alongwith the paths
	cout<<endl<<endl<<"distance of 0 from "<<endl;
	stack<int> s1;
	for(int i=0;i<=n-1;i++){

		cout<<"   "<<i<<"  ----->  "<<dist[i]<<"      " <<"Path"<<"  ----->  ";
		
		int x=i;
		while(x!=0){
			s1.push(x);
			x=parent[x];
		}
		s1.push(x);
		while(!s1.empty()){
			int x = s1.top();
			s1.pop();
			cout<<x<<" ";
		}
		cout<<endl;
	}
	cout<<endl;





}

int main(){

	int n,e;

	cin>>n>>e;

	vector<pii> *g1=new vector<pair<int,int>>[n]; // g1 is an array of vectors (representing Adjacency List)

	for(int i=0;i<=n-1;i++){
		g1[i].clear();
	}

	for(int i=0;i<=e-1;i++){
		int s,e,w;					// s->e is an edge from vertex s to vertex e with weight w

		cin>>s>>e>>w;
		g1[s].push_back(make_pair(e,w));
		g1[e].push_back(make_pair(s,w));
	}

	dijkstra(g1,n,0);


	return 0;
}

/*

input
-------
9 14
0 1 4
0 7 8
1 7 11
1 2 8
2 8 2
8 7 7
8 6 6
7 6 1
2 3 7
2 5 4
6 5 2
3 5 14
3 4 9
5 4 10



output
-------
distance of 0 from 
   0  ----->  0      Path  ----->  0 
   1  ----->  4      Path  ----->  0 1 
   2  ----->  12      Path  ----->  0 1 2 
   3  ----->  19      Path  ----->  0 1 2 3 
   4  ----->  21      Path  ----->  0 7 6 5 4 
   5  ----->  11      Path  ----->  0 7 6 5 
   6  ----->  9      Path  ----->  0 7 6 
   7  ----->  8      Path  ----->  0 7 
   8  ----->  14      Path  ----->  0 1 2 8 

*/

