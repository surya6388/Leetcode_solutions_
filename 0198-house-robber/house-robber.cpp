// 0198. House Robber [Medium]
// https://leetcode.com/problems/house-robber/
//
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
//
//
//
// Example 1:
//
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
//
// Example 2:
//
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 100
//
// 	- 0 <= nums[i] <= 400

// --- First accepted solution (2025-07-23) ---

class Solution {
public:
// state of DP : a set of all the parameters which can identify a subproblem uniquely.
    int f(vector<int>& arr,int i,vector<int> &dp){
        if(i== arr.size()-1) return arr[i]; // single house 
        if(i == arr.size()-2) return max(arr[i],arr[i+1]); // 2 houses
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(arr[i] + f(arr,i+2,dp) , 0 + f(arr,i+1,dp));// (rob,didn't)
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp(n,-1);
        return f(nums,0,dp);
        
    }
};
