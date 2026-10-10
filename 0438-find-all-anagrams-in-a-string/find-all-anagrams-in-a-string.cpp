// 0438. Find All Anagrams in a String [Medium]
// https://leetcode.com/problems/find-all-anagrams-in-a-string/
//
// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
//
//
//
// Example 1:
//
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
//
// Example 2:
//
// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".
//
//
//
// Constraints:
//
// 	- 1 <= s.length, p.length <= 3 * 104
//
// 	- s and p consist of lowercase English letters.

// --- First accepted solution (2026-09-06) ---

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length()<p.length()) return {};
        vector<int> freq1(26,0);
        vector<int> freq2(26,0);
        vector<int> v;
        for(auto x:p){
            freq2[x -'a']++;
        }
        int left =0;
        for(int right=0;right<s.length();right++){
            freq1[s[right]-'a']++;
            while(right-left + 1 > p.length()){
                freq1[s[left]-'a']--;
                left++;
            }
            if(freq1==freq2) v.push_back(left);
        }
        return v;
        
        
    }
};
