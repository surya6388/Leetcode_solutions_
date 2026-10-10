// 0507. Perfect Number [Easy]
// https://leetcode.com/problems/perfect-number/
//
// A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.
//
// Given an integer n, return true if n is a perfect number, otherwise return false.
//
//
//
// Example 1:
//
// Input: num = 28
// Output: true
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// 1, 2, 4, 7, and 14 are all divisors of 28.
//
// Example 2:
//
// Input: num = 7
// Output: false
//
//
//
// Constraints:
//
// 	- 1 <= num <= 108

// --- First accepted solution (2025-06-20) ---

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int s=0;
        for(int i=1;i<sqrt(num);i++){
            if(num % i==0) s+=i;
        }
        for(int i=sqrt(num);i>=1;i--){
            if(num % i==0) s+=(num/i);
        }
        s-=num;
        bool flag=false;
        if(s==num) return true;
        else return false;
        
    }
};
