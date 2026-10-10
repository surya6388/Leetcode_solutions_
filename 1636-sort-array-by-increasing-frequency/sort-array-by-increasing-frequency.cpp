// 1636. Sort Array by Increasing Frequency [Easy]
// https://leetcode.com/problems/sort-array-by-increasing-frequency/
//
// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
//
// Return the sorted array.
//
//
//
// Example 1:
//
// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
//
// Example 2:
//
// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
//
// Example 3:
//
// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 100
//
// 	- -100 <= nums[i] <= 100

// --- First accepted solution (2025-07-14) ---

class Solution {
public:
    typedef pair<int,int> pi;
// Custom comparator inside class
    struct cmp {
        bool operator()(const pi &a, const pi &b) {
            if (a.first == b.first)
                return a.second < b.second; // if freq same, larger val comes first
            return a.first > b.first;       // min heap: smaller freq first
        }
    };
    vector<int> frequencySort(vector<int>& nums) { 
        vector<int> ans;
        unordered_map<int,int> m;//<ele,freq>
        int n = nums.size() ;
        // array to map
        for(int i=0 ;i<n ;i++){
            m[nums[i]]++;
        }
        priority_queue<pi,vector<pi> , cmp > pq;
        // map to heap
        for(auto x: m){
            pq.push({x.second,x.first});// <freq, val>
        }
        // heap to ans array
        for(auto x: m){
            int y=pq.top().second;
            for(int i=0;i< (pq.top().first);i++){
                ans.push_back(y);
            }
            pq.pop();
        }
        return ans;



        
    }
};
