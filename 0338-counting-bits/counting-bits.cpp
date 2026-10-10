// 0338. Counting Bits [Easy]
// https://leetcode.com/problems/counting-bits/
//
// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.
//
// Do not solve it with built-in functions (i.e., like __builtin_popcount in C++).
//
//
// Example 1:
//
// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
//
// Example 2:
//
// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101
//
//
//
// Constraints:
//
// 	- 0 <= n <= 105
//
//
//
// Follow up:
//
// 	- It is very easy to come up with a solution with a runtime of O(n log n). Can you do it in linear time O(n) and possibly in a single pass?

// --- First accepted solution (2026-08-17) ---

class Solution {
public:
    int binary(int n){
        int count = 0;
        while(n!=0){
            int r=n%2;
            if(r==1) count++;
            n/=2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> v;
        int x;
        for(int i=0;i<=n;i++){
            x = binary(i);
            v.push_back(x);
        }
        return v;




        
    }
};
