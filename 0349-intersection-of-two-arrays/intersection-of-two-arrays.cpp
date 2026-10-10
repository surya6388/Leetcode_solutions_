// 0349. Intersection of Two Arrays [Easy]
// https://leetcode.com/problems/intersection-of-two-arrays/
//
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
//
//
//
// Example 1:
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
//
// Example 2:
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.
//
//
//
// Constraints:
//
// 	- 1 <= nums1.length, nums2.length <= 1000
//
// 	- 0 <= nums1[i], nums2[i] <= 1000

// --- First accepted solution (2026-08-06) ---

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        vector<int> v;
        for(int x:nums1){
            s1.insert(x);
        }
        for(int x:nums2){
            s2.insert(x);
        }
        for(auto num:s2){
            if(s1.find(num)!=s1.end()){
                v.push_back(num);
            }
        }
        
    


        return v;
    }
};
