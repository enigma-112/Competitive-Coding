#include<iostream>
using namespace std;


void merge(int *arr,int s,int e){

	int mid = (s+e)/2;

	int i=s;
	int j=mid+1;
	int k=0;

	int * arrtemp = new int[e-s+1];
	while(i<=mid&&j<=e){

		if(arr[i]<=arr[j]){
			arrtemp[k++]=arr[i++];

		}
		else{

			arrtemp[k++]=arr[j++];
		}

	}

	while(i<=mid){
		arrtemp[k++]=arr[i++];
	}
	while(j<=e){
		arrtemp[k++]=arr[j++];
	}

	for(int i=0,j=s;j<=e;i++,j++){

		arr[j]=arrtemp[i];

	}
}

void mergeSort(int *arr,int s,int e){

	if(s>=e){

		return;
	}

	int mid = (s+e)/2;

	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	merge(arr,s,e);
}
int main(){

	int n;

	cin>>n;

	int * arr = new int [n];

	for(int i=0;i<=n-1;i++){

		cin>>arr[i];
	}

	mergeSort(arr,0,n-1);

	for(int i=0;i<=n-1;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}