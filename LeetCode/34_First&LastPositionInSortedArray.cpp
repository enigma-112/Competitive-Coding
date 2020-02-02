// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

// 34. Find First and Last Position of Element in Sorted Array


class Solution {
public:
    
    int findPosition(vector<int> arr,int target,int whichOne){
        int n = arr.size();
        if(n==0){
            return -1;
        }
        
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){
                ans=mid;
                if(whichOne == 0){
                    high=mid-1;
                }
                else{
                    low = mid+1;
                }
                
            }
            else if(target > arr[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstPosition = findPosition(nums,target,0);
        int lastPosition = findPosition(nums,target,1);
        
        vector<int> ans;
        ans.push_back(firstPosition);
        ans.push_back(lastPosition);
        return ans;
        
    }
};