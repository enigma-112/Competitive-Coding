// Floyd–Warshall's Algorithm

/* Concept

	if( d[i][j] > d[i][k] + d[k][j] ){
	
		d[i][j] = d[i][k] + d[k][j];
		path[i][j] = path[k][j];
	}

*/

#include<bits/stdc++.h>
using namespace std;


void FloydWarshall(int ** g1, int n,int e){


   // distance matrix and path matrix --> (we can even make a static 2-D array like  int dis[n][n];)

	int ** dis = new int * [n];
	int ** path = new int* [n];
	for(int i=0;i<=n-1;i++){
		dis[i] = new int [n];
		path[i] = new int[n];
	}

	// initializing distance matrix & path matrix
	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-1;j++){
			dis[i][j]=g1[i][j];
			if(dis[i][j]!=INT_MAX && i!=j){
				path[i][j] = i;
			}
			else{
				path[i][j] = -1;
			}
		}
	}


	for(int k=0;k<=n-1;k++){
		for(int i=0;i<=n-1;i++){
			for(int j=0;j<=n-1;j++){

				if(dis[i][k]==INT_MAX || dis[k][j]==INT_MAX){
					continue;
				}
				if(dis[i][j] > dis[i][k] + dis[k][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}


	// checking for negative weight cycle

	for(int i=0;i<=n-1;i++){
		if(dis[i][i] < 0){
			cout<<"Negative weight cycle is present "<<endl;
		}
	}

	//printing the distance matrix

	for(int i=0;i<=n-1;i++){
		for(int j=0;j<=n-1;j++){
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}


	

}

void printPath(int ** path,int n,  int i, int j){

	if(i < 0 || j< 0 || i >= n || j >= n){
		cout<<"Enter correct vertices "<<endl;
		return ;
	}

	stack<int>  st1 ;

	st1.push(j);

	while(1){

		j = path[i][j];
		if(j == -1){
			return;
		}

		st1.push(j);

		if(j == i){
			break;
		}
	}

	while(!st1.empty()){
		cout<<st1.top();
		st1.pop();
	}

}


int main(){
	
	int n,e;
	cin>>n>>e;

	int ** g1 = new int* [n];

	for(int i=0;i<=n-1;i++){
		g1[i] = new int[n];


		for(int j=0;j<=n-1;j++){
			if(i==j){
				g1[i][j]=0;
			}
			else{
				g1[i][j]=INT_MAX;
			}

		}
	} 


	for(int i=0;i<=e-1;i++){
		int x,y,w;
		cin>>x>>y>>w;
		g1[x][y] = w;
	}

	FloydWarshall(g1,n,e);


}
