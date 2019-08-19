#include<bits/stdc++.h>
using namespace std;

int kthLargest (vector<int> arr, int n, int k){
   
    
    priority_queue<int,vector<int>,greater<int>> pq1;
    for(int i=0;i<=k-1;i++){
        pq1.push(arr[i]);
           
    }
    for(int i =k;i<=n-1;i++){
        if(pq1.top()<arr[i]){
            pq1.pop();
            pq1.push(arr[i]);
        }
    }
    
    return pq1.top();
}

// Main Function


int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
}

