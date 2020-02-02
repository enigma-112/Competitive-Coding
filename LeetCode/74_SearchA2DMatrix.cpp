// https://leetcode.com/problems/search-a-2d-matrix/

// 74. Search a 2D Matrix

// T: O(log(m*n))





class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m= matrix.size();
        if(m==0){return false;}
        int n=matrix[0].size();
        int low = 0,high = m*n-1;
        int mid_index,mid_element;
        while(low<=high){
             mid_index = (low+high)/2;
             mid_element = matrix[mid_index/n][mid_index%n];
            if(target==mid_element){return true;}
            else if(target < mid_element){
                high = mid_index-1;
            }
            else{
                low=mid_index+1;
            }
        }
        return false;
        
    }
};