// 1493. Longest Subarray of 1's After Deleting One Element [Medium]
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
//
// You are given a binary array nums, you should delete one element from it.
//
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
//
//
//
// Example 1:
//
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
//
// Example 2:
//
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
//
// Example 3:
//
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 105
//
// 	- nums[i] is either 0 or 1.

// --- First accepted solution (2025-06-17) ---

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int n=nums.size();
    int maxlen=INT_MIN,len=INT_MIN;
    int flips=0;
    int k=1;
    int i=0;
    int j=0;
    while(j<n){
        if(nums[j]==1) j++;
        else{// nums[j]==0
            if(flips < k){
                flips++;
                j++;
            }
            else{// flips==k
                // calculate length
                len=j-i;
                maxlen=max(maxlen,len);
                // i ko just uske aage wale ek index se aage jao
                while(nums[i]==1) i++;// after this nums[i]=0
                i++;
                j++;
            }

        }

    }
    len=j-i;
    maxlen=max(maxlen,len);
    return maxlen-1;
        
    }
};
