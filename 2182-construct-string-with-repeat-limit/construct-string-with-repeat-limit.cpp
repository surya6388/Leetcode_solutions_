// 2182. Construct String With Repeat Limit [Medium]
// https://leetcode.com/problems/construct-string-with-repeat-limit/
//
// You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.
//
// Return the lexicographically largest repeatLimitedString possible.
//
// A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.
//
//
//
// Example 1:
//
// Input: s = "cczazcc", repeatLimit = 3
// Output: "zzcccac"
// Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
// The letter 'a' appears at most 1 time in a row.
// The letter 'c' appears at most 3 times in a row.
// The letter 'z' appears at most 2 times in a row.
// Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
// The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
// Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
//
// Example 2:
//
// Input: s = "aababab", repeatLimit = 2
// Output: "bbabaa"
// Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa".
// The letter 'a' appears at most 2 times in a row.
// The letter 'b' appears at most 2 times in a row.
// Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
// The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
// Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
//
//
//
// Constraints:
//
// 	- 1 <= repeatLimit <= s.length <= 105
//
// 	- s consists of lowercase English letters.

// --- First accepted solution (2025-07-21) ---

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> m; // max heap<char,freq>
        for(int i=0;i< s.length();i++){
            m[s[i]]++;
        }
        priority_queue<pair<char,int> > pq;
        for(auto x:m){
            pq.push({x.first,x.second});
        }
        string result="";
        while(pq.size()>0){
            auto largest =  pq.top();
            pq.pop();
            int len = min(repeatLimit,largest.second);
            for(int i=0;i<len;i++){
                result += largest.first;
            } 
            pair<char,int> secondlargest ;
            if(largest.second-len >0 ){
                if(!pq.empty()){
                    secondlargest = pq.top();
                    pq.pop();
                    result += secondlargest.first;
                }
                else return result;
                if(secondlargest.second-1 >0 ) pq.push({secondlargest.first,secondlargest.second-1} );
            pq.push({largest.first,largest.second-len});
            }
            
            
            
        }
        return result;

        
    }
};
