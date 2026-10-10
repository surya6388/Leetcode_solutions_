// 0003. Longest Substring Without Repeating Characters [Medium]
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
//
// Given a string s, find the length of the longest substring without duplicate characters.
//
//
//
// Example 1:
//
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
//
// Example 2:
//
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
//
// Example 3:
//
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
//
//
// Constraints:
//
// 	- 0 <= s.length <= 105
//
// 	- s consists of English letters, digits, symbols and spaces.

// --- First accepted solution (2025-08-22) ---

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0 || s.length()==1) return s.length();
        int count=0;
        int maxcount=0;
        for(int i=0;i<s.length();i++){
            unordered_set<char> m;
            count=0;
            for(int j=i;j<s.length();j++){
                if(m.find(s[j]) != m.end()) break;
                m.insert(s[j]);
                count++;
            }
            maxcount=max(count,maxcount);
        }
        return maxcount;
    }
};
