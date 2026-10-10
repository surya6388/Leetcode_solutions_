// 0205. Isomorphic Strings [Easy]
// https://leetcode.com/problems/isomorphic-strings/
//
// Given two strings s and t, determine if they are isomorphic.
//
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
//
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
//
//
//
// Example 1:
//
// Input: s = "egg", t = "add"
//
// Output: true
//
// Explanation:
//
// The strings s and t can be made identical by:
//
// 	- Mapping 'e' to 'a'.
//
// 	- Mapping 'g' to 'd'.
//
// Example 2:
//
// Input: s = "f11", t = "b23"
//
// Output: false
//
// Explanation:
//
// The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.
//
// Example 3:
//
// Input: s = "paper", t = "title"
//
// Output: true
//
//
//
// Constraints:
//
// 	- 1 <= s.length <= 5 * 104
//
// 	- t.length == s.length
//
// 	- s and t consist of any valid ascii character.

// --- First accepted solution (2026-09-10) ---

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> v1(256,-1);
        vector<int> v2(256,-1);
        for(int i=0;i<s.size();i++){
            unsigned char ch1=s[i];
            unsigned char ch2=t[i];
            if(v1[ch1]==-1 && v2[ch2]==-1){
                v1[ch1]=ch2;
                v2[ch2]=ch1;
            }
            else{
                if(v1[ch1]!=ch2 || v2[ch2]!=ch1){
                    return false;
                }
            }
        }
        return true;
        
    }
};
