// 0231. Power of Two [Easy]
// https://leetcode.com/problems/power-of-two/
//
// Given an integer n, return true if it is a power of two. Otherwise, return false.
//
// An integer n is a power of two, if there exists an integer x such that n == 2x.
//
//
//
// Example 1:
//
// Input: n = 1
// Output: true
// Explanation: 20 = 1
//
// Example 2:
//
// Input: n = 16
// Output: true
// Explanation: 24 = 16
//
// Example 3:
//
// Input: n = 3
// Output: false
//
//
//
// Constraints:
//
// 	- -231 <= n <= 231 - 1
//
//
//
// Follow up: Could you solve it without loops/recursion?

// --- First accepted solution (2026-08-17) ---

class Solution {
public:
// a number in the power two has only 1 ones in its binary representation 
    int binary(int n) {
        int count = 0;
        while(n != 0) {
            int r = n % 2;
            if(r == 1) count++;
            n /= 2;
        }
        return count;
    }
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        int x = binary(n);
        return x == 1;
    }
};
