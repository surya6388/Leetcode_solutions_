// 0190. Reverse Bits [Easy]
// https://leetcode.com/problems/reverse-bits/
//
// Reverse bits of a given 32 bits signed integer.
//
//
//
// Example 1:
//
// Input: n = 43261596
//
// Output: 964176192
//
// Explanation:
//
//
//
// 			Integer
// 			Binary
//
//
// 			43261596
// 			00000010100101000001111010011100
//
//
// 			964176192
// 			00111001011110000010100101000000
//
//
//
// Example 2:
//
// Input: n = 2147483644
//
// Output: 1073741822
//
// Explanation:
//
//
//
// 			Integer
// 			Binary
//
//
// 			2147483644
// 			01111111111111111111111111111100
//
//
// 			1073741822
// 			00111111111111111111111111111110
//
//
//
//
//
// Constraints:
//
// 	- 0 <= n <= 231 - 2
//
// 	- n is even.
//
//
//
// Follow up: If this function is called many times, how would you optimize it?

// --- First accepted solution (2026-08-17) ---

class Solution {
public:
    string binary(uint32_t n) {
        string s;

        for(int i = 0; i < 32; i++) {
            int r = n % 2;
            s += r + '0';
            n /= 2;
        }

        return s;
    }

    uint32_t reverseBits(uint32_t n) {
        string s = binary(n);

        uint32_t sum = 0;
        uint32_t x = 1;

        for(int i = 31; i >= 0; i--) {
            sum += x * (s[i] - '0');
            x *= 2;
        }

        return sum;
    }
};
