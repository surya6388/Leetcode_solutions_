// 1155. Number of Dice Rolls With Target Sum [Medium]
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
//
// You have n dice, and each dice has k faces numbered from 1 to k.
//
// Given three integers n, k, and target, return the number of possible ways (out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. Since the answer may be too large, return it modulo 109 + 7.
//
//
//
// Example 1:
//
// Input: n = 1, k = 6, target = 3
// Output: 1
// Explanation: You throw one die with 6 faces.
// There is only one way to get a sum of 3.
//
// Example 2:
//
// Input: n = 2, k = 6, target = 7
// Output: 6
// Explanation: You throw two dice, each with 6 faces.
// There are 6 ways to get a sum of 7: 1+6, 2+5, 3+4, 4+3, 5+2, 6+1.
//
// Example 3:
//
// Input: n = 30, k = 30, target = 500
// Output: 222616187
// Explanation: The answer must be returned modulo 109 + 7.
//
//
//
// Constraints:
//
// 	- 1 <= n, k <= 30
//
// 	- 1 <= target <= 1000

// --- First accepted solution (2026-09-05) ---

#define ll long long int
#define mod ( 1000000007)
class Solution {
public:
// state of dp is defined by 2 variable n and k so 2D vector is required for memorisation
    ll f(int n, int k, int target,vector<vector<ll> > &dp){
        if(n==0 && target==0) return 1;
        if(n==0 && target!=0) return 0; //sum cannot be reduced to 0 as number of dices ended  
        if(dp[n][target] !=-1) return dp[n][target];
        ll result=0;
        for(int i=1;i<=k;i++){
                if(target-i <0) continue;
                result =((result % mod) + f(n-1,k,target-i,dp)% mod)%mod;
            
        }
        return dp[n][target] = result % mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll> > dp;
        dp.clear();
        dp.resize(n+5,vector<ll> (target+5,-1));
        ll x = f(n,k,target,dp);
        return x;
        
    }
};
