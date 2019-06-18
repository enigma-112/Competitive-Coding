// Factorial for big integers (using array)


#include<bits/stdc++.h>
using namespace std;


void find_factorial(int *arr,int &index_till,int i){

	int carry = 0;
	int j=0;
	for(;j<=index_till-1;j++){

		int x = arr[j]*i;

		int n1 = x+carry;

		carry = n1/10;

		arr[j]=n1%10;
	}

	while(carry){

		int n2 = carry%10;
		arr[j]=n2;
		j++;
		index_till++;
		carry = carry/10;
	}

}

int main(){

	int n;
	cin>>n;

	int * arr = new int[100000]{0}; 

	arr[0]=1;

	int  index_till=1;
	

	for(int i=2;i<=n;i++){

		find_factorial(arr,index_till,i);
	}


	//Printing the factorial

	for(int i =index_till-1;i>=0;i--){

		cout<<arr[i];
	}

	cout<<endl<<endl;
	cout<<"size of factorial : "<<index_till<<endl;



}