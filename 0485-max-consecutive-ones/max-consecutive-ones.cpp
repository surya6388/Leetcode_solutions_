// 0485. Max Consecutive Ones [Easy]
// https://leetcode.com/problems/max-consecutive-ones/
//
// Given a binary array nums, return the maximum number of consecutive 1's in the array.
//
//
//
// Example 1:
//
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
//
// Example 2:
//
// Input: nums = [1,0,1,1,0,1]
// Output: 2
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 105
//
// 	- nums[i] is either 0 or 1.

// --- First accepted solution (2026-10-06) ---

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count;
        int maxcount=0;
        if(nums.size()==1 && nums[0]==1) return 1;
        else if(nums.size()==1 && nums[0]==0) return 0;
        bool flag=true;
        for(int i=0;i<nums.size();i++){
            count=0;
            int j=i;
            if(nums[i]==1){
                count++;
                while(i+1!=nums.size() && nums[i]==nums[i+1]){
                i++;
                count++;
                
                } 
            }
            
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};
