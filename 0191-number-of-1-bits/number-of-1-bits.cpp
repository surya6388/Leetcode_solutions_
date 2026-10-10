// 0191. Number of 1 Bits [Easy]
// https://leetcode.com/problems/number-of-1-bits/
//
// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).
//
//
//
// Example 1:
//
// Input: n = 11
//
// Output: 3
//
// Explanation:
//
// The input binary string 1011 has a total of three set bits.
//
// Example 2:
//
// Input: n = 128
//
// Output: 1
//
// Explanation:
//
// The input binary string 10000000 has a total of one set bit.
//
// Example 3:
//
// Input: n = 2147483645
//
// Output: 30
//
// Explanation:
//
// The input binary string 1111111111111111111111111111101 has a total of thirty set bits.
//
//
//
// Constraints:
//
// 	- 1 <= n <= 231 - 1
//
//
//
// Follow up: If this function is called many times, how would you optimize it?

// --- First accepted solution (2026-08-17) ---

class Solution {
public:
    string binary(int n){
        string s;
        while(n!=0){
            int r = n%2;
            s+= r+'0';
            n=n/2;
        }
        return s;
    }
    int hammingWeight(int n) {
        string s = binary(n);
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') count++;
        }
        return count;
        
    }
};
