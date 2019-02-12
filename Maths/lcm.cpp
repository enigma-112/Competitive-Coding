#include<bits/stdc++.h>
using namespace std;



int GCD(int a,int b){

if(b==0){
	return a;
}
	
return GCD(b,a%b);

}

int LCM(int a,int b){
	return (a*b)/GCD(a,b); // lcm(a,b)*gcd(a,b)==a*b
}

int main(){


int a,b;
cout<<" Enter the two no.s : ";
cin>>a>>b;

int lcm = LCM( a, b);
cout<<"LCM of "<< a<<" and "<<b <<" is "<<lcm<<endl;



}