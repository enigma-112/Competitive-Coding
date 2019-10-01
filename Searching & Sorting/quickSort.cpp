#include<iostream>
using namespace std;


int partition(int *arr,int s,int e){


	int i=s-1;
	int j=s;
	int pivot=arr[e];

	for( ; j<=e-1;j++ ){

		if(arr[j]<=pivot){
			i++;
			swap(arr[i],arr[j]);
			
			

		}	
	}


	swap(arr[i+1],arr[e]);
	return i+1;
}

void quickSort(int *arr,int s,int e){

	if(s>=e){
		return;
	}

	int pivot = partition(arr,s,e);

	quickSort(arr,s,pivot-1);
	quickSort(arr,pivot+1,e);
}

int main(){

int n;
cin>>n;

int * arr = new int[n];
for(int i=0;i<=n-1;i++){
	cin>>arr[i];
}

quickSort(arr,0,n-1);

for(int i=0;i<=n-1;i++){
	cout<<arr[i]<<" ";
}
}