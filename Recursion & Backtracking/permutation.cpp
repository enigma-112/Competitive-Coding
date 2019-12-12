#include<iostream>
using namespace std;



void permute(string s1,int i){

	if(i==s1.length()-1){
		cout<<s1<<endl;
		return;
	}


	for(int j=i;j<=s1.length()-1;j++){

		swap(s1[i],s1[j]);
		permute(s1,i+1);
		swap(s1[i],s1[j]);
	}


}
int main(){

	string s1;
	cin>>s1;
	permute(s1,0);
}