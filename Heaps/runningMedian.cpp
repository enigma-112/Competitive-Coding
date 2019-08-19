#include<bits/stdc++.h>
using namespace std;
void findMedian(int arr[], int n){
   

    priority_queue<int> maxh;
    priority_queue<int,vector<int>,greater<int>> minh;
    
    int i=0;
    maxh.push(arr[i]);   // inserting the 0th element in the maxHeap
    cout<<arr[i]<<endl;
    i++;
    for(;i<=n-1;i++){

        // inserting the ith element
        if(arr[i]<=maxh.top()){
            maxh.push(arr[i]);
        }
        else{
            minh.push(arr[i]);
        }
        
        // balancing the size of the two heaps

        if(abs(maxh.size()-minh.size())>=2){
            if(maxh.size()>minh.size()){
                int x = maxh.top();
                maxh.pop();
                minh.push(x);
            }
            else{
                int x = minh.top();
                minh.pop();
                maxh.push(x);
            }
            
        }
        
        
        
        //finding median
        
            int x = maxh.size()+minh.size();
            if(x%2==0){
                cout<<(maxh.top()+minh.top())/2<<endl;
            }
            else{
                
                if(maxh.size()>minh.size()){
                    cout<<maxh.top()<<endl;
                }
                else{
                    cout<<minh.top()<<endl;
                }
                
            }
    }
    
}

// Main function


int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    findMedian(arr, n);
    
    delete [] arr;
    
}
