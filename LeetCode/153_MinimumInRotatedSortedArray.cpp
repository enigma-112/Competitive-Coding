// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// 153. Find Minimum in Rotated Sorted Array





class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        if(n==1){           // if there is only one element 
            return arr[0];
        }
        if(arr[n-1]>arr[0]){ // if there is no rotation , array is just sorted
            return arr[0];
        }
        
        while(low<=high){
                int mid = (low+high)/2;
                 if( mid+1<=n-1 &&  arr[mid] > arr[mid+1] ){
                    return arr[mid+1];
                  }
                else if( mid-1>=0 && arr[mid] < arr[mid-1]){
                    return arr[mid];
                }
               
                else if( arr[mid] <arr[low]){ // if left part is unsorted
                    high = mid-1;
                }
            else{         // if right part is unsorted 
                low = mid+1;    
            }
            
        }
        return 0;
    }
};