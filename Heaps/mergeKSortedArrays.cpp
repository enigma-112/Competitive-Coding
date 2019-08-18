#include<bits/stdc++.h>
using namespace std;


class triplet {
    public:    
        int data;
        int arr;
        int index;       
};



bool compare(triplet x,triplet y){
    
    if(x.data<=y.data){
        return true;
    }
    else{
        return false;
    }
}


vector<int> mergeKSortedArrays(vector<vector<int>*> input){

  priority_queue<triplet,vector<triplet>, bool (*)(triplet, triplet)> pq1(compare) ;

  int size = input.size();

  triplet t1;
  for(int i=0;i<=input.size()-1;i++){

            vector<int> * v = input[i];
            t1.data = v->at(0);
            t1.arr = i;
            t1.index =0;
            cout<<t1.data<<endl;
  }

 vector<int> output;
  while(pq1.empty()==false){

    triplet x = pq1.top();
    cout<<x.data<<endl;
      output.push_back(x.data);
    pq1.pop();


    if(x.index +1 <= (input[x.arr]->size()-1)){
            t1.data = input[x.arr]->at(x.index+1);
            t1.arr = x.arr;
            t1.index = x.index+1;
            pq1.push(t1);


    }


  }
return output;


}


int main() {
    
    int k;
    cin >> k;
    vector<vector<int>*> input;
    for(int j = 1; j <= k; j++) {
        int size;
        cin >> size;
        vector<int> *current = new vector<int>;
        
        for(int i = 0; i < size; i++) {
            int a;
            cin >> a;
            current -> push_back(a);
        }
        input.push_back(current);
    }
    
    
    vector<int> output = mergeKSortedArrays(input);

    for(int i = 0; i < output.size(); i++)
        cout << output[i] << " ";
    
    return 0;
}
