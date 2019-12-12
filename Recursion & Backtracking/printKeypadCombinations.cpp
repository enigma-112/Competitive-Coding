#include <iostream>
#include <string>
using namespace std;

string arr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void find_ans(int num,string s){
    if(num==0){
        cout<<s<<endl;
        return;
    }
    
    int x=num%10;   
    
     if(x==0||x==1){
     	find_ans(num/10,s);

     }
     else{
    for(int i=0;i<arr[x].size();i++){            
          	
            find_ans(num/10,arr[x][i]+s);
                  
    }   
}

    
}

void printKeypad(int num){   
    string s;
     find_ans(num,s);    
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
