#include<iostream>
#include<unordered_map>
using namespace std;

//unordered_map<int,string> m1;

string m1[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void keypad(string input,char output[], int i,int j){

	//cout<<"First --->"<<"i : "<<i<<"    ,   "<<"j  :  "<<j<<endl;
	if(j==input.length()){

		output[j]='\0';
		cout<<output<<endl;
		return;
	}

//cout<<"Second --->"<<"i : "<<i<<"    ,   "<<"j  :  "<<j<<endl;
	int digit = input[i]-'0';

	 if(digit==0||digit==1){

		keypad(input,output,i+1,j);
	 }

	
//cout<<"Third --->"<<"i : "<<i<<"    ,   "<<"j  :  "<<j<<endl;
	for(int x=0;x<=m1[digit].length()-1;x++){


			output[j]=m1[digit][x];
			keypad(input,output,i+1,j+1);
	}



}

int main(){

	//m1[0]="",m1[1]="",m1[2]="abc",m1[3]="def",m1[4]="ghi",m1[5]="jkl",m1[6]="mno",m1[7]="pqrs",m1[8]="tuv",m1[9]="wxyz";
	// we can also take the input in a character array or  string array .


	string input;
	cin>>input;
	int n = input.length();
	char output[n];
	keypad(input,output,0,0);

}