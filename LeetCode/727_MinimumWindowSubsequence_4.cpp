 /*
    https://leetcode.com/problems/minimum-window-subsequence/discuss/109362/Java-Super-Easy-DP-Solution-(O(mn)
 
    figuring out what dp[i][j] means is keypoint:
dp[i][j] means: for S(0~i) & T(0~j), the "largest" starting index in S which matches T. I think share2017 didn't say largest explicitly, 
some friends got confused in the comments for this. Since its the largest starting index, so for String T with length 1, if it matches S(i), 
it should be index i.
In my solution, I didn't use +1 trick, maybe it's easier to understand @share2017 idea. Thanks!


 */






 string minWindow(string S, string T) {
        int len1 = S.length();
        int len2 = T.length();
        if(len1==0 || len2 == 0){
            return "";
        }
        int dp[len2][len1];
      

    //----Filling first row    
        for(int j=0;j<=len1-1;j++){   
            if(S[j]==T[0]){         
                dp[0][j]=j;         // largest starting index matches only first char in T
            }
            else{
                if(j==0){
                 dp[0][j]=-1;      // S, T both have 1 char, if !match, fill -1 means we can't find a substring for S(0) & T(0)
                }
                else{
                 dp[0][j]=dp[0][j-1];
                }
                
            }
        }
        
    //----Filling First column-- It means pattern(T) is of length i+1(i.e 2,3,4,...) but string(S) is 
    //----of length 1, so no subsequence will be found    
        for(int i=1;i<=len2-1;i++){
            dp[i][0]=-1;
        }
    //----Filling the remaining 1 to len2-1 rows
        for(int i=1;i<=len2-1;i++){
            for(int j=1;j<=len1-1;j++){
                if(T[i]==S[j]){                   
                    dp[i][j]=dp[i-1][j-1];
                }
                else{                                     
                    dp[i][j]=dp[i][j-1];
                }
                }
            }
        
        
    //----Finding the minimum substring
        int start=-1,min_len=INT_MAX;
        for(int j=0;j<=len1-1;j++){
            if(dp[len2-1][j]!=-1){
                if(j-dp[len2-1][j]+1<min_len){
                    start = dp[len2-1][j];
                    min_len=j-dp[len2-1][j]+1;
                }
            }
        }
        
        return (start==-1) ? "" : S.substr(start,min_len); 
        
        
    }