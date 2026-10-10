// 0322. Coin Change [Medium]
// https://leetcode.com/problems/coin-change/
//
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
//
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
// You may assume that you have an infinite number of each kind of coin.
//
//
//
// Example 1:
//
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
//
// Example 2:
//
// Input: coins = [2], amount = 3
// Output: -1
//
// Example 3:
//
// Input: coins = [1], amount = 0
// Output: 0
//
//
//
// Constraints:
//
// 	- 1 <= coins.length <= 12
//
// 	- 1 <= coins[i] <= 231 - 1
//
// 	- 0 <= amount <= 104

// --- First accepted solution (2026-09-05) ---

class Solution {
public:
    int f(vector<int>& coins, int amount,vector<int>& dp){
        if(amount==0) return 0;
        if(dp[amount]!=-2) return dp[amount];
        int result=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]<0) continue; // if the denomination is more than amount , we can take it
            result = min(result,f(coins,amount - coins[i],dp));
        } 
        if(result == INT_MAX) return dp[amount]=INT_MAX;
        return dp[amount]=1+result;
       

    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-2);
        int x = f(coins,amount,dp);
        if(x!=INT_MAX) return x;
        else return -1;
    }
};
