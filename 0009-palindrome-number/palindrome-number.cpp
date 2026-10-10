// 0009. Palindrome Number [Easy]
// https://leetcode.com/problems/palindrome-number/
//
// Given an integer x, return true if x is a palindrome, and false otherwise.
//
//
//
// Example 1:
//
// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
//
// Example 2:
//
// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
// Example 3:
//
// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
//
//
// Constraints:
//
// 	- -231 <= x <= 231 - 1
//
//
//
// Follow up: Could you solve it without converting the integer to a string?

// --- First accepted solution (2025-08-23) ---

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long n = (long long)x;
        long long sum=0;
        while(x!=0){
            long long r=x%10;
            sum = sum * 10 + r;
            x/=10;
        }
        if(sum ==(long long) n) return true;
        else return false;
    }
};
