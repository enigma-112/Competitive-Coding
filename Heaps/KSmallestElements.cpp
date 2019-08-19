#include<bits/stdc++.h>
using namespace std;
vector<int> kSmallest(int *input, int n, int k) {
	
    
    priority_queue<int> pq1;
    
    for(int i=0;i<=k-1;i++){
        pq1.push(input[i]);
    }
    
    for(int i=k;i<=n-1;i++){
        int x = pq1.top();
        
        if(x>input[i]){
            pq1.pop();
            pq1.push(input[i]);
        }
    }
    
    vector<int> v1;
    
    while(pq1.empty()==false){
        
        v1.push_back(pq1.top());
        pq1.pop();
    }
    
    return v1;
}


// Main Function

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }
    int k;
    cin >> k;
    vector<int> output = kSmallest(input, n, k);
    for(int i = 0; i < output.size(); i++){
        cout << output[i] << endl;
    }
}
