// https://leetcode.com/problems/minimum-size-subarray-sum/solution/

// 209. Minimum Size Subarray Sum

// T : O(N)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n =nums.size();
        int ans=INT_MAX;
        
        int i=0,curr_sum=0;
        for(int j=0;j<=n-1;j++){
            curr_sum += nums[j];
            while(curr_sum >=s ){
                ans = min(ans, j-i+1);
                curr_sum -= nums[i];
                i++;
            }
        }
        
        return (ans==INT_MAX) ? 0 : ans;
        
    }
};



// ---------- My Solution (Rough)--Accepted
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n =nums.size();
        int len=INT_MAX;
        
         int curr_sum=0;
         int curr_len=0;
        for(int i=0,j=0;j<=n-1;j++){
           
            while(curr_sum < s && j<=n-1){
                curr_sum += nums[j];
                j++;
            }
            j--;
            if(curr_sum>=s){
                curr_len = j-i+1;
                len = min(len,curr_len);
            }
          
            
            
            while(curr_sum >= s ){
                curr_sum -= nums[i];
                i++;
                 if(curr_sum>=s){
                curr_len = j-i+1;
                len = min(len,curr_len);
            }
                
            }
            
       }
        if(len==INT_MAX){
            return 0;
        }
        return len;
        
    }
};