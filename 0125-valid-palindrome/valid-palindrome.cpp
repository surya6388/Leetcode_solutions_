// 0125. Valid Palindrome [Easy]
// https://leetcode.com/problems/valid-palindrome/
//
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
//
// Given a string s, return true if it is a palindrome, or false otherwise.
//
//
//
// Example 1:
//
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
//
// Example 2:
//
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
//
// Example 3:
//
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
//
//
//
// Constraints:
//
// 	- 1 <= s.length <= 2 * 105
//
// 	- s consists only of printable ASCII characters.

// --- First accepted solution (2026-10-06) ---

class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90){
                char ch=(s[i])+32;
                ans+=ch;
            }
            else if(s[i]>=97 && s[i]<=122){
                ans+=s[i];
            }
            else if(s[i]>='0' && s[i]<='9'){
                ans+=(s[i]);
            }
        }
        int n=ans.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(ans[i]!=ans[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
