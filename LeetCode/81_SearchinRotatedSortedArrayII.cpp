// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/


//81. Search in Rotated Sorted Array II

// T : O(n)

// Solution 1
class Solution {
public:
    bool search(vector<int>& arr, int target) {
        
         int n = arr.size();
        if(n==0){
            return false;
        }
        
        int low =0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid] > arr[high]){ // mid lies on left side
                if(target>=arr[low] && target < arr[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else if(arr[mid]<arr[high]){ // mid lies on right side
                
                if(target>arr[mid] && target<=arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
                 
            }
            else{
                high--;
            }
            
        }
        
        return false;
        
    }
};

// Spolution 2 : GFG

class Solution {
public:
    bool search(vector<int>& arr, int target) {
       
        int n = arr.size();
        if(n==0){
            return false;
        }
        
        int low =0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                return true;
            }
            else if(arr[mid]==arr[low] && arr[mid]==arr[high]){  // This is the change from previous solution
                 low++,high--;
            }
            else if(arr[mid] >= arr[low]){ // mid lies on left side
                if(target>=arr[low] && target < arr[mid]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else { // mid lies on right side
                
                if(target>arr[mid] && target<=arr[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
                 
            }
            
        }
        
       return false;
  
    }
};