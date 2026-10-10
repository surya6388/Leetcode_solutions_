// 0461. Hamming Distance [Easy]
// https://leetcode.com/problems/hamming-distance/
//
// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
//
// Given two integers x and y, return the Hamming distance between them.
//
//
//
// Example 1:
//
// Input: x = 1, y = 4
// Output: 2
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// The above arrows point to positions where the corresponding bits are different.
//
// Example 2:
//
// Input: x = 3, y = 1
// Output: 1
//
//
//
// Constraints:
//
// 	- 0 <= x, y <= 231 - 1
//
//
//
// Note: This question is the same as  2220: Minimum Bit Flips to Convert Number.

// --- First accepted solution (2026-08-17) ---

class Solution {
public:
    string binary(int n){
        string s;
        while(n!=0){
            int r=n%2;
            s+=(r+'0');
            n/=2;
        }
         reverse(s.begin(),s.end());
        return s;
    }
    int hammingDistance(int x, int y) {
        int n;
        string s1=binary(x);
        string s2=binary(y);
      
       if(s1.length() < s2.length()) {
            n = s2.length() - s1.length();
            s1.insert(0, n, '0');
        }
        else {
            n = s1.length() - s2.length();
            s2.insert(0, n, '0');
        }
        int count=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) count++;

        }
        return count;

        
    }
};
