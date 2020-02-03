// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

// 167. Two Sum II - Input array is sorted

// T : O(N)



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        for(int i=0,j=n-1;i<j;){
            if(numbers[i]+numbers[j]==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
        
    }
};