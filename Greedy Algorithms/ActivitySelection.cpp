

#include <iostream>
#include<algorithm>
using namespace std;

class activity{
    public:
        int start;
        int finish;
        int num;
};

bool compare(activity a,activity b){
    return a.finish < b.finish;
}

void find_ans(activity arr[],int n){
    
    sort(arr,arr+n,compare);
    int i=0;
    cout<<arr[i].num<<" ";
    for(int j=1;j<=n-1;j++){
        if(arr[j].start>=arr[i].finish){
            cout<<arr[j].num<<" ";
            i=j;
        }
    }
    cout<<endl;
}
int main() {
    int t;
    cin>>t;

    while(t--){
        
        int n;
        cin>>n;
        activity arr[n];
        for(int i=0;i<=n-1;i++){
            int x;
            cin>>x;
            arr[i].start=x;
            arr[i].num = i+1;
        }
        
          for(int i=0;i<=n-1;i++){
            int x;
            cin>>x;
            arr[i].finish=x;
        }
        
        find_ans(arr,n);
    
    }
}