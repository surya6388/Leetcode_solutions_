// 0347. Top K Frequent Elements [Medium]
// https://leetcode.com/problems/top-k-frequent-elements/
//
// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
//
//
//
// Example 1:
//
// Input: nums = [1,1,1,2,2,3], k = 2
//
// Output: [1,2]
//
// Example 2:
//
// Input: nums = [1], k = 1
//
// Output: [1]
//
// Example 3:
//
// Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
//
// Output: [1,2]
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 105
//
// 	- -104 <= nums[i] <= 104
//
// 	- k is in the range [1, the number of unique elements in the array].
//
// 	- It is guaranteed that the answer is unique.
//
//
//
// Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

// --- First accepted solution (2025-07-14) ---

class Solution {
public:
typedef pair<int,int> pi; // macros
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // map pair is(ele,freq);
        unordered_map<int,int> m;
        for(int ele : nums){
            m[ele]++;
        }
        // heap pair is <freq,ele> as min element which will be at top considered as per first
        priority_queue<pi , vector<pi>,greater<pi> > pq;//min heap;
        int n=nums.size();
        for(auto x:m){
            pq.push({x.second,x.first});// <freq,element>
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);// pq me element 2nd index pe store hai use push 
            pq.pop();
        }
        return ans;
    }
};
