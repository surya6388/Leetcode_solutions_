// 0128. Longest Consecutive Sequence [Medium]
// https://leetcode.com/problems/longest-consecutive-sequence/
//
// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
//
// You must write an algorithm that runs in O(n) time.
//
//
//
// Example 1:
//
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
//
// Example 2:
//
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
//
// Example 3:
//
// Input: nums = [1,0,1,2]
// Output: 3
//
//
//
// Constraints:
//
// 	- 0 <= nums.length <= 105
//
// 	- -109 <= nums[i] <= 109

// --- First accepted solution (2026-08-05) ---

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x:nums){
            s.insert(x);
        }
        int maxcount=0;
        //Start counting only if the current number is the beginning of a sequence.
        // A number is the beginning if num-1 is not in the set.
        for(auto y:s){
            if(s.find(y - 1) == s.end()){
                int count =1;
                int ele=y;
                while(s.find(ele+1)!=s.end()){
                    count++;
                    ele++;
                }  
                maxcount = max(count,maxcount);   
            }
        }
        return maxcount;
        
    }
};
