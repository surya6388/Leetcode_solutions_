// 0005. Longest Palindromic Substring [Medium]
// https://leetcode.com/problems/longest-palindromic-substring/
//
// Given a string s, return the longest palindromic substring in s.
//
//
//
// Example 1:
//
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
//
// Example 2:
//
// Input: s = "cbbd"
// Output: "bb"
//
//
//
// Constraints:
//
// 	- 1 <= s.length <= 1000
//
// 	- s consist of only digits and English letters.

// --- First accepted solution (2026-02-08) ---

class Solution {
public:
    void expand(string &s,int left , int right, int &start ,int &maxlen){
        while(left>=0 && right < s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        int length = right - left -1;
        if(length>maxlen){
            maxlen = length;
            start = left+1;
        }
    }
    string longestPalindrome(string s) {
        if(s.length()==0) return "";
        int n = s.length();
        int start=0;
        int maxlen = 1;
        for(int i=0;i<n;i++){
            expand(s,i,i,start,maxlen);
            expand(s,i,i+1,start,maxlen);
        }
        return s.substr(start,maxlen);
    }
};
