// 0007. Reverse Integer [Medium]
// https://leetcode.com/problems/reverse-integer/
//
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
//
//
//
// Example 1:
//
// Input: x = 123
// Output: 321
//
// Example 2:
//
// Input: x = -123
// Output: -321
//
// Example 3:
//
// Input: x = 120
// Output: 21
//
//
//
// Constraints:
//
// 	- -231 <= x <= 231 - 1

// --- First accepted solution (2025-09-09) ---

class Solution {
public:
    int reverse(int x) {
        int sum =0;
        while(x!=0){
            int r = x %10;
            if (sum > INT_MAX / 10 || (sum == INT_MAX / 10 && r > 7)) return 0;
            if (sum < INT_MIN / 10 || (sum == INT_MIN / 10 && r < -8)) return 0;
            
            sum = sum *10+r;
            x/=10;

        }
        return sum;
    }
};
