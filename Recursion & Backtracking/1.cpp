#include<bits/stdc++.h> 
using namespace std; 
  
void insertInNonDecOrder(deque<char> &dq, char ch) 
{ 
   
    if (dq.empty()) 
        dq.push_back(ch); 
  
    else
    { 
        char temp = dq.back(); 
  
        
        while( temp > ch && !dq.empty()) 
        { 
            dq.pop_back(); 
            if (!dq.empty()) 
                temp = dq.back(); 
        } 
        dq.push_back(ch); // insert the current digit 
    } 
    return; 
} 
  
string buildLowestNumber(string str, int n) 
{ 
    int len = str.length(); 
  
  
    int k = len - n; 
  
    deque<char> dq; 
    string res = ""; 
  
   
    int i; 
    for (i=0; i<=len-k; i++) 
  
        
        insertInNonDecOrder(dq, str[i]); 
  
   
    while (i < len) 
    { 
       
        res += dq.front(); 
  
       
        dq.pop_front(); 
  
       
        insertInNonDecOrder(dq, str[i]); 
        i++; 
    } 
  
    
    res += dq.front(); 
    dq.pop_front(); 
    return res; 
} 
  

int main() 
{ 
    int t;
    cin>>t;
    while(t--){

        int n;
        cin>>n;
        string s;
        while(n){
            int t =n%10;
            char x = t+48;
            s=x+s;
            n=n/10;
        }

     

   int k=1;  
   string ans= buildLowestNumber(s, k);
   cout<<stoi(ans)<<endl;
    


    }
}