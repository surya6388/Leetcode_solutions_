// 0060. Permutation Sequence [Hard]
// https://leetcode.com/problems/permutation-sequence/
//
// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
//
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
// 	- "123"
//
// 	- "132"
//
// 	- "213"
//
// 	- "231"
//
// 	- "312"
//
// 	- "321"
//
// Given n and k, return the kth permutation sequence.
//
//
//
// Example 1:
//
// Input: n = 3, k = 3
// Output: "213"
//
// Example 2:
//
// Input: n = 4, k = 9
// Output: "2314"
//
// Example 3:
//
// Input: n = 3, k = 1
// Output: "123"
//
//
//
// Constraints:
//
// 	- 1 <= n <= 9
//
// 	- 1 <= k <= n!

// --- First accepted solution (2025-06-09) ---

class Solution {
public:
    string helper(string str,int k,string ans){
    int n=str.length();
    if(n==0){ 
        return ans;
    }
    // chunk for 1 digit
    int fact=1;
    for(int i=2;i<n;i++){// fact(n-1)
        fact *= i;
    }
    int idx=k/fact;
    if(k % fact == 0) idx--;
    // removing that character 
    char ch=str[idx];
    string left=str.substr(0,idx);
    string right=str.substr(idx+1);
    // for k
    int q=1;
    if(k % fact == 0) q=fact;
    else q=k % fact;
    return helper(left + right,q,ans + ch);



}
string getPermutation(int n, int k) {
    string str="";
    for(int i=1;i<=n;i++){
        str += to_string(i);
    }
    return helper(str,k,"");
         
}
};
