// https://leetcode.com/problems/search-insert-position/

// 35. Search Insert Position


class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        if(n==0){ return 0; }
        if(target < arr[0]){return 0;}
        if(target>arr[n-1]){return n;}
        int low=0,high = n-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid]==target){return mid;}
            else if(target<arr[mid]){
                ans=mid;
                high=mid-1;
            }
            else{
                
                low=mid+1;
            }
        }
        return ans;
    }
};