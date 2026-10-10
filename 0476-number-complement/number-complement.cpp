// 0476. Number Complement [Easy]
// https://leetcode.com/problems/number-complement/
//
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
//
// 	- For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
//
// Given an integer num, return its complement.
//
//
//
// Example 1:
//
// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
//
// Example 2:
//
// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
//
//
//
// Constraints:
//
// 	- 1 <= num < 231
//
//
//
// Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

// --- First accepted solution (2026-08-17) ---

class Solution {
public:
    string binary(int n){
        string s;
        while(n!=0){
            int r=n%2;
            (r==0)? s+=(1+'0'):s+=( 0+'0');
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int findComplement(int num) {
        string s = binary(num);
        long long x=1;
        int sum=0;
        for(int i=s.length()-1;i>=0;i--){
            sum+=(x*(s[i]-'0'));
            x*=2;
        }
        return sum;
        
    }
};
