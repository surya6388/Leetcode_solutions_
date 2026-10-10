// 0049. Group Anagrams [Medium]
// https://leetcode.com/problems/group-anagrams/
//
// Given an array of strings strs, group the anagrams together. You can return the answer in any order.
//
//
//
// Example 1:
//
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
//
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
//
// Explanation:
//
// 	- There is no string in strs that can be rearranged to form "bat".
//
// 	- The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
//
// 	- The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
//
// Example 2:
//
// Input: strs = [""]
//
// Output: [[""]]
//
// Example 3:
//
// Input: strs = ["a"]
//
// Output: [["a"]]
//
//
//
// Constraints:
//
// 	- 1 <= strs.length <= 104
//
// 	- 0 <= strs[i].length <= 100
//
// 	- strs[i] consists of lowercase English letters.

// --- First accepted solution (2025-07-14) ---

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>> ans; 
        unordered_map<string,vector<string>> m;
        for(string str: arr){
            string lexo = str;
            sort(lexo.begin(),lexo.end());
            if(m.find(lexo) == m.end()){// nhi mila
                vector<string> v;
                v.push_back(str);
                m[lexo]=v;
            }
            else{// mila  
                m[lexo].push_back(str);

            }
        }
        for(auto x: m){
            vector<string> v2 =x.second;
            ans.push_back(v2);
        }
        return ans;

    }
};
