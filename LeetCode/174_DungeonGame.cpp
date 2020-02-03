// https://leetcode.com/problems/dungeon-game/

// 174. Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int m=dungeon.size();
        int n=dungeon[0].size();
        
        int dp[m][n];
        int x = 1-dungeon[m-1][n-1];
       dp[m-1][n-1] = (x<=0) ? 1 : x;
        
        // filling last column
        for(int i = m-2;i>=0;i--){
            int x = dp[i+1][n-1] - dungeon[i][n-1];
            dp[i][n-1]= (x<=0) ? 1 : x;
            
        }
        
     // filling last row
        
    for(int j=n-2;j>=0;j--){
        int x = dp[m-1][j+1] - dungeon[m-1][j];
            dp[m-1][j]= (x<=0) ? 1 : x;
    }
        
    // filling the rest of cells
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                int x = min(dp[i+1][j]-dungeon[i][j], dp[i][j+1]-dungeon[i][j]);
                 dp[i][j] = (x<=0) ? 1 : x;
            }
        }
        return dp[0][0];
        
    }
};