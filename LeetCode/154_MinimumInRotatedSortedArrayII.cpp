//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

// 154. Find Minimum in Rotated Sorted Array II



class Solution {
public:
    int findMin(vector<int>& nums) {
           int low = 0, high = nums.size() - 1;

    while (low < high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] < nums[high])
        high = mid;
      else if (nums[mid] > nums[high])
        low = mid + 1;
      else
        high -= 1;
    }
    return nums[low];
    }
    
};