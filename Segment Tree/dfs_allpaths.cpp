#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void  get_path(int ** g,int V,bool* visited,int v1,int v2,vector<int> ans){
   
    
visited[v1]=true;
ans.push_back(v1);

       
    if(v1==v2){
        for(int i=0;i<=ans.size()-1;i++){
        
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else{
    
    
    for(int i=0;i<=V-1;i++){
        if(i==v1){
            continue;
        }
            
        if(g[v1][i]==1&&!visited[i]){
           
            get_path(g,V,visited,i,v2,ans);
            
        }
    }
}
ans.pop_back();
visited[v1]=false;
   
    
}
int main() {
    int V, E;
    cin >> V >> E;
    
    int ** g=new int*[V];
    for(int i=0;i<=V-1;i++){
        g[i]=new int[V];
        for(int j=0;j<=V-1;j++){
            g[i][j]=0;
        }
    }
    
    for(int i=0;i<=E-1;i++){
        int f,s;
        cin>>f>>s;
        g[f][s]=1;
       
    }
  
    int v1,v2;
    cin>>v1>>v2;
    bool *visited=new bool[V];
    for(int i=0;i<=V-1;i++){
        visited[i]=false;
    }
    vector<int> ans;
    get_path(g,V,visited,v1,v2,ans);
    
       // if(answer!=NULL){
       //     for(int i=0;i<=answer->size()-1;i++){
       //         cout<<answer->at(i)<<" ";
       //     }
       // }
  return 0;
}
