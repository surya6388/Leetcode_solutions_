// 0202. Happy Number [Easy]
// https://leetcode.com/problems/happy-number/
//
// Write an algorithm to determine if a number n is happy.
//
// A happy number is a number defined by the following process:
//
// 	- Starting with any positive integer, replace the number by the sum of the squares of its digits.
//
// 	- Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//
// 	- Those numbers for which this process ends in 1 are happy.
//
// Return true if n is a happy number, and false if not.
//
//
//
// Example 1:
//
// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
//
// Example 2:
//
// Input: n = 2
// Output: false
//
//
//
// Constraints:
//
// 	- 1 <= n <= 231 - 1

// --- First accepted solution (2026-08-06) ---

class Solution {
public:

    int squareSum(int N,unordered_set<int> &s){
        if(N==1) return 1;
        if(s.find(N)!=s.end()) return 0;
        int sum=0;
        s.insert(N);
        while(N!=0){
            int x = N%10;
            sum+=(x*x);
            N/=10;
        }
        return squareSum(sum,s);
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        int x = squareSum(n,s);
        return bool(x);

        
        
    }
};
