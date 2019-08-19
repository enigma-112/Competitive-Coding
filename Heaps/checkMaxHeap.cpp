#include<bits/stdc++.h>
using namespace std;

bool checkMaxHeap(int arr[], int n){
  
    
    for(int i=0;i<=n-1;i++){
        int leftChildIndex = 2*i+1;
        int rightChildIndex = 2*i+2;
        if((leftChildIndex)<= (n-1)){
            
            if(arr[i]<arr[leftChildIndex]){
                return false;
            }
            
            if(arr[i]<arr[rightChildIndex]){
                return false;
            }
            
            
        }
        else{
            return true;
        }
    }
}

// Main Function

int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
}
