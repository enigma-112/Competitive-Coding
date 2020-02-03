// https://leetcode.com/problems/find-peak-element/

// 162. Find Peak Element

// T : O(log N)



// --------------------------------------------- doing : (low+high)/2 , high=mid , low = mid+1
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int low = 0,high = n-1;
        while(low<high){
            int mid = (low+high)/2;
            if(nums[mid] > nums[mid+1] ){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};



// --------------------------------------------- doing : (low+high+1)/2 , high = mid-1, low =mid
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n= nums.size();
        int low = 0,high = n-1;
        while(low<high){
            int mid = (low+high+1)/2;
            if(nums[mid] < nums[mid-1] ){
                high=mid-1;
            }
            else{
                low=mid;
            }
        }
        return low;
        
    }
};