// 0283. Move Zeroes [Easy]
// https://leetcode.com/problems/move-zeroes/
//
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
// Note that you must do this in-place without making a copy of the array.
//
//
//
// Example 1:
//
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Example 2:
//
// Input: nums = [0]
// Output: [0]
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 104
//
// 	- -231 <= nums[i] <= 231 - 1
//
//
//
// Follow up: Could you minimize the total number of operations done?

// --- First accepted solution (2026-10-06) ---

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        int count=0;
        while(i<nums.size()){
            if( nums[i]==0){
                nums.erase(nums.begin()+i);
                count++;
            }
            else i++;
            
        }
        for(int j=1;j<=count;j++){
            nums.push_back(0);
        }
        
        
    }
};
