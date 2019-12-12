#include<bits/stdc++.h>
using namespace std;



void helper(char str[], int count[], char result[], int level,int n) {
        if (level == n) {
            result[n]='\0';
            cout<<result<<endl;
            return;
        }

        for(int i = 0; i <= strlen(str)-1; i++) {
            if(count[i] == 0) {
                continue;
            }
            result[level] = str[i];
            count[i]--;
           helper(str, count, result, level + 1, n);
            count[i]++;
        }
    }

void permutation(string s){

	map<char,int> m1;

	for(int i=0;i<=s.length()-1;i++){

		m1[s[i]]++;
	}

	char str[m1.size()+1];

	int count[m1.size()];

	char result[s.length()+1];

	int i=0;
	for(auto x : m1){
			str[i]=x.first;
			count[i]=x.second;
			i++;
	}


	str[i]='\0';
	//sort(str,str+strlen(str));

	helper(str,count,result,0,s.length());
}


int main(){

	string s;
	cin>>s;
	permutation(s);
}


