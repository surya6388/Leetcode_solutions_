// 0022. Generate Parentheses [Medium]
// https://leetcode.com/problems/generate-parentheses/
//
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// Example 1:
//
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
//
// Example 2:
//
// Input: n = 1
// Output: ["()"]
//
//
//
// Constraints:
//
// 	- 1 <= n <= 8

// --- First accepted solution (2025-06-08) ---

class Solution {
public:
void gp(vector<string> &v,string s,int n,int o,int c){
    if(c==n && o==n){
        v.push_back(s);
        return;

    }
    
    if(o<n){
        gp(v,s+'(',n,o+1,c); 
    }
    
    if(o > c){
        gp(v,s+')',n,o,c+1);
        
    }

}

    vector<string> generateParenthesis(int n) {
        vector<string> v;
        gp(v,"",n,0,0);
        return v;
        
    }
};
