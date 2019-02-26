#include<bits/stdc++.h>
using namespace std;

#define N 9




bool findEmpty(int arr[N][N],int &row,int &col){

for(int i=0;i<=N-1;i++){
	for(int j=0;j<=N-1;j++){
		if(arr[i][j]==0){
			row=i;
			col=j;
			return true;
		}

	}
}
return false;
}
bool isSafe(int arr[N][N],int row,int col,int k){

	// checking for row
	for(int j=0;j<=N-1;j++){
		if(arr[row][j]==k)
			return false;
	}
	// checking for col
	for(int i=0;i<=N-1;i++){
		if(arr[i][col]==k)
			return false;
	}

	// checking for box

	int row_factor=row-(row%3);
    int	col_factor=col-(col%3);

	for(int i=0;i<=2;i++){
		for(int j=0;j<=2;j++){
			if(arr[i+row_factor][j+col_factor]==k)
				return false;
		}
	}

return true;


}






bool solveSudoku(int arr[N][N]){

int row,col;

if(findEmpty(arr,row,col)==false){
	return true;
}


for(int i=1;i<=9;i++){
	if(isSafe(arr,row,col,i)){
		arr[row][col]=i;
		if(solveSudoku(arr)==true)
			return true;

		arr[row][col]=0;

	}

}

	
return false;




}

int main(){

int arr[N][N];

for(int i=0;i<=N-1;i++){

	string s;
	cin>>s;
	for(int j=0;j<=s.length()-1;j++){

		arr[i][j]=s[j]-'0';
	}
}


solveSudoku(arr);
for(int i=0;i<=N-1;i++){
	for(int j=0;j<=N-1;j++){
		cout<<arr[i][j];
	}
	cout<<endl;
}

return  0;

}