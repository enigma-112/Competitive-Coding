// Kruskal's algorithm  ---> Time Complexity : O(E.LogE + E.logV)
// Cycle detection is done with the help of disjoint set -> union find algorithm with optimizations i.e using union by rank and path-compression

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

class dSet{  // this is class of a disjoint set , it is used to detect cycle in undirected and connected graph

	int * rank;
	int * parent;
	int n;
	public:

		dSet(int size){
			n = size;
			parent = new int[size];
			rank = new int[size];
			for(int i=0;i<=size-1;i++){
				parent[i] = i;
				rank[i] = 0;
			}

		}


	int find1( int n ,int i){  // find by path compression

			if(parent[i]==i){
				return i;
			}

			parent[i] = find1(n,parent[i]);

			return parent[i];

	}

	void union1(int n, int i,int j){	// union by rank

			int iroot = find1(n,i);
			int jroot = find1(n,j);

			if(iroot == jroot){
				return;
			}

			if(rank[iroot]<rank[jroot]){
				parent[iroot]=jroot;
			}
			else if(rank[jroot]<rank[iroot]){
				parent[jroot] = iroot;
			}
			else{
				parent[iroot]=jroot;
				rank[jroot]+=1;
			}
	}


};



class edge{

 public:
 	int s; // source
 	int d; // destination
 	int w; // weight
};

bool compare(edge & x , edge & y){
	return x.w < y.w;
}
void kruskal(edge * input,int n,int e){

	dSet   disjoint(n);

	sort(input,input+e,compare);
	vector<pii> v1;

	int mincost=0;
	for(int i=0;i<=e-1;i++){
		int x = input[i].s;
		int y = input[i].d;

		

		int xroot = disjoint.find1(n,x);
		int yroot = disjoint.find1(n,y);

		if(xroot==yroot){
			continue;
		}
		else{
			v1.push_back(make_pair(x,y));
			mincost+= input[i].w;
			disjoint.union1(n,x,y);

		}
	}
	cout<<endl<<endl<<mincost<<endl;

	cout<<endl<<"Edges in MST are :"<<endl ;
	for(pii x : v1){
		cout<<x.first<<" --- "<<x.second<<endl;
	}
}
int main(){

	int n,e;
	cin>>n>>e;

	edge * input = new edge[e]; // input is the array of edges

	for(int i=0;i<=e-1;i++){

		int s,d,w;
		cin>>s>>d>>w;
		input[i].s = s;
		input[i].d = d;
		input[i].w = w;

	}

	kruskal(input,n,e);
	
}