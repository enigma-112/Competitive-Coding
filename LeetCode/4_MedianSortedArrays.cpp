// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/

// 4. Median of Two Sorted Arrays




class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n1 = (int)arr1.size();
         int n2 = (int)arr2.size();
        if(n2<n1){
           return findMedianSortedArrays(arr2,arr1);
        }
        
        int total  = n1+n2;
        int low=0, high = n1;
        int elementsInFirstPartition = (total+1)/2;
        
        while(low<=high){
            int c1 = (low+high)/2;
            int c2 = elementsInFirstPartition - c1;
            if(c1<= (high-1) && arr1[c1] < arr2[c2-1]){
                low = c1+1;
            }
            else if( c1>=(low+1) && arr1[c1-1] > arr2[c2]){
                high = c1-1;
            }
            else{
                int maxLeft,minRight;
                // Finding maxLeft
                if(c1==0){
                    maxLeft = arr2[c2-1];
                }
                else if(c2==0){
                    maxLeft = arr1[c1-1];
                }
                else {
                    maxLeft = max(arr1[c1-1],arr2[c2-1]);
                }
                if(total%2 == 1){ // If total no. of elements are odd
                    return maxLeft;
                }

                // Finding minRight
                if(c1==n1){
                    minRight = arr2[c2];
                }
                else if(c2==n2){
                    minRight = arr1[c1];
                }
                else{
                    minRight = min(arr1[c1],arr2[c2]);
                }
                return (maxLeft+minRight)/2.0;
            }
            
        }
        
        return 0;
    }
};