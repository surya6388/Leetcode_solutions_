// 0974. Subarray Sums Divisible by K [Medium]
// https://leetcode.com/problems/subarray-sums-divisible-by-k/
//
// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.
//
// A subarray is a contiguous part of an array.
//
//
//
// Example 1:
//
// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
//
// Example 2:
//
// Input: nums = [5], k = 9
// Output: 0
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 3 * 104
//
// 	- -104 <= nums[i] <= 104
//
// 	- 2 <= k <= 104

// --- First accepted solution (2026-10-08) ---

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n);
        unordered_map<int,int> m;
        int count=0;
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1] + nums[i];
        }
        for(int i=0;i<n;i++){
            int rem2 = pre[i]%k ;
            if(rem2 <0) rem2+=k;
            if(rem2==0) count++;
            if(m.find(rem2)!=m.end()){
                count+=m[rem2];
            }
            m[rem2]++;
        }
        return count;
    }
};
