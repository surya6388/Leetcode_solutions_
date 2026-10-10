// 0215. Kth Largest Element in an Array [Medium]
// https://leetcode.com/problems/kth-largest-element-in-an-array/
//
// Given an integer array nums and an integer k, return the kth largest element in the array.
//
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// Can you solve it without sorting?
//
//
//
// Example 1:
//
// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
//
// Example 2:
//
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4
//
//
//
// Constraints:
//
// 	- 1 <= k <= nums.length <= 105
//
// 	- -104 <= nums[i] <= 104

// --- First accepted solution (2025-07-14) ---

class Solution {
public:
    int findKthLargest(vector<int>& v, int k) {
        priority_queue<int,vector<int>, greater<int> > pq;// minheap
        int n=v.size();
        for(int i=0;i<n;i++){
        pq.push(v[i]);
        if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
