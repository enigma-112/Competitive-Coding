#include <iostream>
#include<utility>
#include<algorithm>
using namespace std;

class x{
    public:
    int weight;
    int value;
};

bool compare(x a, x b){
    double t1 = (double)a.value/a.weight;
    double t2 = (double)b.value/b.weight;
    return t1>t2;
}
double find_ans(x arr[],int n,int capacity){
     
     double ans=0;
     sort(arr,arr+n,compare);
     
     for(int i=0;i<=n-1;i++){
         if(capacity>0){
             if(capacity>=arr[i].weight){
                 ans+=(double)arr[i].value;
                 capacity-=arr[i].weight;
             }
             else{
                 ans+= (((double)arr[i].value)/arr[i].weight)*capacity;
                 capacity=0;
             }
         }
         else{
             break;
         }
     }
     
    return ans;
}

int main() {

    int t;
    cin>>t;
    while(t--){
        
        int n,capacity;
        cin>>n>>capacity;
        x arr[n];
        for(int i=0;i<=n-1;i++){
            int a,b;
            cin>>a>>b;
            arr[i].value=a;
            arr[i].weight=b;
        }
        printf("%.2f",find_ans(arr,n,capacity));
        cout<<endl;
    }
    
}