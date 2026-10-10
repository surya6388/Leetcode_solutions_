// 0075. Sort Colors [Medium]
// https://leetcode.com/problems/sort-colors/
//
// You are given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
//
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
//
// You must solve this problem without using the library's sort function.
//
//
//
// Example 1:
//
// Input: nums = [2,0,2,1,1,0]
//
// Output: [0,0,1,1,2,2]
//
// Explanation:
//
// The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.
//
// Example 2:
//
// Input: nums = [2,0,1]
//
// Output: [0,1,2]
//
// Explanation:
//
// The array has one each of 0, 1, and 2, arranged in-place in the order 0, 1, 2.
//
//
//
// Constraints:
//
// 	- n == nums.length
//
// 	- 1 <= n <= 300
//
// 	- nums[i] is either 0, 1, or 2.
//
//
//
// Follow up: Could you come up with a one-pass algorithm using only constant extra space?

// --- First accepted solution (2025-03-27) ---

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int no0=0;
        int no1=0;
        int no2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) no0++;
            else if(nums[i]==1) no1++;
            else no2++;
        }
        for(int i=0;i<n;i++){
            if(i<no0) nums[i]=0;
            else if(i<(no0+no1)) nums[i]=1;
            else nums[i]=2;

        }
        return;
        
    }
        
    
};
