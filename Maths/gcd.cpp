#include<bits/stdc++.h>
using namespace std;



int GCD(int a,int b){

if(b==0){
	return a;
}
	
return GCD(b,a%b);

}


int main(){


int a,b;
cout<<" Enter the two no.s : ";
cin>>a>>b;

int gcd = GCD( a, b);
cout<<"GCD of "<< a<<" and "<<b <<" is "<<gcd<<endl;



}