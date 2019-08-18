#include<bits/stdc++.h>
using namespace std;

int main(){

	int n;
	cin>>n;


	int zer_n =0;
	int pos_n =0;
	int neg_n =0;
	int min_pos =INT_MAX;
	int min_pos_i=-1;
	int max_neg = INT_MIN;
	int max_neg_i = -1;
	int all_n = 1;

//	int flag=0;
	int arr[n];

	for(int i=0;i<=n-1;i++){
		int x;
		cin>>x;
//----------------------
		if(x==0){
			x=-1;
		}
		if(x>0&& x<min_pos){
			min_pos = x;
		}

		if(x<0 && x > max_neg && x!=-1){
			max_neg = x;
		}

		// if(x<0){
		// 	flag=1;
		// }
		// if(x==0){
		// 	zer_n ++;
		// }
		if(x>0){
			pos_n ++;
		}
		if(x<0){
			neg_n ++;
		}
		if(x<0 && x!=-1){
			all_n = 0;
		}
		 arr[i]=x;
		
	}


		
		if(pos_n==0){


				if(all_n ==1&&neg_n%2!=0){
					arr[0]=0;
				}
				else if(neg_n%2!=0){
				
					max_neg = -1*max_neg -1;
				}
			

		}
		else if(neg_n==0){
				int flag =0;
				if(pos_n%2!=0){
					for(int i=0;i<=n-1;i++){
						if(arr[i]==min_pos&&flag==0){
							flag=1;
						}
						else{
							arr[i]=-1*arr[i]-1;
						}
					}
				}
				else{

					for(int i=0;i<=n-1;i++){
						arr[i]=-1*arr[i]-1;
					}

			}

		}

		else if(all_n==1){

					if(pos_n%2 ==0 && neg_n%2==0 && pos_n!=0){
						for(int i =0;i<=n-1;i++){
							if(arr[i]>0 ) {
								arr[i] = -1*arr[i]-1;
						}

					}
			}	
					else if(pos_n%2 ==0 && neg_n%2 !=0 && pos_n!=0){
						int flag=0;
						for(int i=0;i<=n-1;i++){
							if(arr[i]==min_pos&&flag==0){
								flag=1;
							}
							else if(arr[i]>0){
							arr[i]=-1*arr[i]-1;
							}
						}


					}


					else if(pos_n%2 !=0 && neg_n%2 ==0 && pos_n!=0){
						int flag=0;
						for(int i=0;i<=n-1;i++){
							if(arr[i]==min_pos&&flag==0){
								flag=1;
							}
							else if(arr[i]>0){
							arr[i]=-1*arr[i]-1;
							}
						}



			}


					else if(pos_n%2 !=0 && neg_n%2!=0){

						if(pos_n%2 ==0 && neg_n%2==0 && pos_n!=0){
							for(int i =0;i<=n-1;i++){
								if(arr[i]>0 ) {
									arr[i] = -1*arr[i]-1;
								}

							}
						}



					}

	}

	else {
				if(pos_n %2 ==0 && neg_n%2 ==0 ){

					for(int i =0;i<=n-1;i++){
						if(arr[i]>0 ) {
							arr[i] = -1*arr[i]-1;
						}

				}
			}

				else if(pos_n%2!=0 && neg_n %2 !=0){
						for(int i=0;i<=n-1;i++){
							if(arr[i]>0){
								arr[i]=-1*arr[i]-1;
							}
						}
					}

				else if(pos_n%2==0 && neg_n%2!=0){
					int flag =0;
					int x;
					 if(abs(min_pos)>abs(max_neg)){

					 	x=max_neg;

					 }
					else{
						x=min_pos;
					}

					for(int i=0;i<=n-1;i++){
						if(arr[i]==min_pos && flag==0&&x==min_pos){
								flag=1;
						}
						else if(x==max_neg && flag ==0 && arr[i]==max_neg){
							flag=1;
							arr[i]=-1*arr[i]-1;
						}
						else if(arr[i]>0){
							arr[i]=-1*arr[i]-1;
						}
					}
				}
				else if(pos_n%2!=0 && neg_n%2==0){
					int flag =0;
					int x;
					 if(abs(min_pos)>abs(max_neg)){

					 	x=max_neg;

					 }
					else{
						x=min_pos;
					}

					for(int i=0;i<=n-1;i++){
						if(arr[i]==min_pos && flag==0&&x==min_pos){
								flag=1;
						}
						else if(x==max_neg && flag ==0 && arr[i]==max_neg){
							flag=1;
							arr[i]=-1*arr[i]-1;
						}
						else if(arr[i]>0){
							arr[i]=-1*arr[i]-1;
						}
					}
				}




		}

	for(int i=0;i<=n-1;i++){
				cout<<arr[i]<<" ";
			}

	}    