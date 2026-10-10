// 0017. Letter Combinations of a Phone Number [Medium]
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
//
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
//
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//
//
// Example 1:
//
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
// Example 2:
//
// Input: digits = "2"
// Output: ["a","b","c"]
//
//
//
// Constraints:
//
// 	- 1 <= digits.length <= 4
//
// 	- digits[i] is a digit in the range ['2', '9'].

// --- First accepted solution (2026-06-04) ---

class Solution {
public:
    vector<string> ans;

    void solve(int idx,
               string& digits,
               string& curr,
               unordered_map<char,string>& mp) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }

        string letters = mp[digits[idx]];

        for (char ch : letters) {
            curr.push_back(ch);
            solve(idx + 1, digits, curr, mp);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char,string> mp = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        string curr;
        solve(0, digits, curr, mp);

        return ans;
    }
};
