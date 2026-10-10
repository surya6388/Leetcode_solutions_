// 1497. Check If Array Pairs Are Divisible by k [Medium]
// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
//
// Given an array of integers arr of even length n and an integer k.
//
// We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.
//
// Return true If you can find a way to do that or false otherwise.
//
//
//
// Example 1:
//
// Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
// Output: true
// Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
//
// Example 2:
//
// Input: arr = [1,2,3,4,5,6], k = 7
// Output: true
// Explanation: Pairs are (1,6),(2,5) and(3,4).
//
// Example 3:
//
// Input: arr = [1,2,3,4,5,6], k = 10
// Output: false
// Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
//
//
//
// Constraints:
//
// 	- arr.length == n
//
// 	- 1 <= n <= 105
//
// 	- n is even.
//
// 	- -109 <= arr[i] <= 109
//
// 	- 1 <= k <= 105

// --- First accepted solution (2025-07-14) ---

class Solution {
public:
// take modulo with 'k' of every element of array
// Notice that desired pair's sum is either '0' or 'k' in this array;
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int ,int> m;
        for(int ele: arr){
            ele = ((ele % k) + k) % k;
            m[ele]++;
        }
        if(m.find(0) != m.end()){
            if(m[0] % 2 != 0) return false;// if freq of 0 is not even pairs cannot be formed
            m.erase(0);
        }
        for(auto x: m){
            int rem = k - x.first;
            if(m.find(rem) == m.end()) return false;
            if(m[x.first] != m[rem]) return false;// if freq of element in map is not equal to freq of rem 
        }
        return true;

    }
};
