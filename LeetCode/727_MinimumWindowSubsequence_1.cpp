string minWindow(string S, string T) {
    int n = S.size(), MAX = 1000000;
    vector<int> pre(n + 1, 0), cur(n + 1,MAX);
   
        
    for (int k=0;k<=T.length()-1;k++) {
        char  x = T[k];
        for (int i = 0; i <= n-1; i++) {
          //  cur[i + 1] = 1 + (x == S[i] ? pre[i] : cur[i]);
            
            if(S[i]==x){
                cur[i+1] = 1 + pre[i];
            }
            else{
                cur[i+1] = 1 + cur[i];
            }
        }
        swap(cur, pre);
        cur[0] = MAX;
    }
        
    int i = min_element(pre.begin(), pre.end()) - pre.begin();
    return pre[i] > S.size()   ?   ""   :   S.substr(i - pre[i], pre[i]);
        
        
    }