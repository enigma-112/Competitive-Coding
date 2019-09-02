// Bellman Ford's Algorithm


#include<bits/stdc++.h>
using namespace std;


class edge{

	public:
		int s; //source
		int d; // destination
		int w; //weight
};



void bellmanford(edge * input, int n,int e,int start=0){

	int * dis = new int[n];
	for(int i=0;i<=n-1;i++){
		dis[i]=INT_MAX;
	}

	dis[start]=0;

	for(int i=1;i<=n-1;i++){

		for(int j=0;j<=e-1;j++){

			int from = input[j].s;
			int to = input[j].d;
			int weight = input[j].w;

			if(dis[from]!=INT_MAX && (dis[from]+ weight< dis[to])){
				dis[to] = dis[from] + weight; 
			}
		}
	}

	cout<<endl<<"Distance to different vertices from source are :"<<endl;

	for(int i=0;i<=n-1;i++){
		cout<<i<<"  --->>>  "<<dis[i]<<endl;
	}
}

int main(){
	int n,e;

	cin>>n>>e;

	edge * input = new edge[e];  // input is the array of edges 

	for(int i=0;i<=e-1;i++){

		int a,b,c;    // a = from , b = to , c = weight
		cin>>a>>b>>c;   

		input[i].s = a;
		input[i].d = b;
		input[i].w = c;
	}

	//cout<<endl<<"Enter the start node : ";
	//int start;
	//cin>>start;
	bellmanford(input,n,e,0);

}


/*
	 input
	-------
	5 8
	0 1 -1
	0 2 4
	1 2 3
	1 3 2 
	1 4 2 
	3 2 5
	3 1 1
	4 3 -3

	output
   --------

*/