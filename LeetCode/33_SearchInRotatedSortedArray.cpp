// https://leetcode.com/problems/search-in-rotated-sorted-array/

// 33. Search in Rotated Sorted Array




class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        if(n==0){
            return -1;
        }
        
        int low =0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid] >= arr[low]){ // mid lies on left side
                if(target>=arr[low] && target < arr[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{ // mid lies on right side
                
                if(target>arr[mid] && target<=arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
                 
            }
            
        }
        
        return -1;
    }
};