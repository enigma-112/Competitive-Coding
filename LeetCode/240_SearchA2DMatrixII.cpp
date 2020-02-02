// https://leetcode.com/problems/search-a-2d-matrix-ii/

// 240. Search a 2D Matrix II

// T : O(m+n) , m= no. of rows , n = no. of columns

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        if(row==0){
            return false;
        }
        int col = matrix[0].size();
        
        int x=0,y=col-1;
        while(x<=row-1 && y>= 0){
            if(target==matrix[x][y]){return true;}
            else if(target < matrix[x][y]){y--;}
            else {x++;}
        }
        return false;
    }
};