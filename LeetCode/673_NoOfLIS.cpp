/*

	https://leetcode.com/problems/number-of-longest-increasing-subsequence/
*/

 int findNumberOfLIS(vector<int>& nums) {
        int ans=0,max_len=0;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int dp[n];			// dp[i] means length of LIS ending at index i
        int count[n];		// count[i] means no. of LIS ending at index i
       
        for(int i=0;i<=n-1;i++){	// each element is in itself an LIS of length 1
            dp[i]=1;
            count[i]=1;
        }
        
        for(int i=0;i<=n-1;i++){
            for(int j=0;j<=i-1;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                    else if (dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        count[i]=count[j];
                    }
                }
            }
        }
        
        for(int i=0;i<=n-1;i++){
            if(max_len==dp[i]){
                ans+=count[i];
            }
            if(max_len<dp[i]){
                max_len=dp[i];
                ans=count[i];
                
            }
            
        }
        return ans;
    }