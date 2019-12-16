string minWindow(string S, string T) {
   int m = S.size (), n = T.size (), start = -1 , minLen = INT_MAX, i = 0 , j = 0 ;
         while (i < m) {
             if (S [i] == T [j]) {
                     j++;
                     if (j == n) {
                        int end = i + 1 ;
                        j--;
                         while (j >= 0 ) {
                             while (S [i]!= T [j]){
                                 i--;
                             }
                             i--;
                             j--;
                        }
                        ++ i; ++ j;
                         if (end-i < minLen) {
                            minLen = end- i;
                            start = i;
                         }
                     }  
              }
          i++;
        }
        
        
        return (start!=-1 )? S.substr (start, minLen): "" ;
        
        
    }