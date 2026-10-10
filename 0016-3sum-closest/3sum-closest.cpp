// 0016. 3Sum Closest [Medium]
// https://leetcode.com/problems/3sum-closest/
//
// You are given an integer array nums of length n and an integer target.
//
// Find three integers at distinct indices in nums such that the sum is closest to target.
//
// Return the sum of the three integers.
//
// You may assume that each input would have exactly one solution.
//
//
//
// Example 1:
//
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
// Example 2:
//
// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
//
//
//
// Constraints:
//
// 	- 3 <= nums.length <= 500
//
// 	- -1000 <= nums[i] <= 1000
//
// 	- -104 <= target <= 104

// --- First accepted solution (2025-08-25) ---

class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        int n = v.size();
        sort(v.begin(),v.end());
        int closest= v[0]+v[1]+v[2];
        for(int i=0;i<n-2;i++){
            int j = i+1;
            int k=n-1;
            while(j<k){
                int sum = v[i]+v[j]+v[k];
                if(abs(sum-target) < abs(closest-target)) closest=sum;
                if(sum < target) j++;
                else k--;
            }
        }
        return closest;
        
    }
};
