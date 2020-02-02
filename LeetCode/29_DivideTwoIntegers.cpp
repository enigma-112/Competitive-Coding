// https://leetcode.com/problems/divide-two-integers/


// gfg solution

typedef long long int ll;
class Solution {
public:
    int divide( int dividend,  int divisor) {
      
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; 
        // Edge Case
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        //
        
      
       ll  dividend_temp = abs((long long)dividend); 
       ll divisor_temp  = abs((long long)divisor); 
       
       
      
        
        ll quotient = 0, temp = 0; 
    
        for (int i = 31; i >= 0; --i) { 
           
            if (temp + (divisor_temp << i) <= dividend_temp) { 
                temp += divisor_temp << i; 
                quotient |= 1LL << i; 
            } 
        } 
        
      
        
        return sign * quotient; 
    
    
    }
};

// My solution : hint --> https://www.youtube.com/watch?v=p-KFccIseJE

typedef long long int ll;
class Solution {
public:
    int divide( int dividend,  int divisor) {
      
        // Edge Case
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        //
        
       int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1; 
       ll  dividend_temp = abs((long long)dividend); 
       ll divisor_temp  = abs((long long)divisor); 
       
       
      
        
        ll quotient = 0; 
    
        for (int i = 31; i >= 0; --i) { 
           
            if (dividend_temp >= (divisor_temp<<i)) { 
                dividend_temp -= divisor_temp<<i; 
                quotient += 1<<i; 
            } 
        } 
        
      
        
        return sign * quotient; 
    
    
    }
};