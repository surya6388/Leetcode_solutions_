// 1004. Max Consecutive Ones III [Medium]
// https://leetcode.com/problems/max-consecutive-ones-iii/
//
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
//
//
//
// Example 1:
//
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
//
// Example 2:
//
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 105
//
// 	- nums[i] is either 0 or 1.
//
// 	- 0 <= k <= nums.length

// --- First accepted solution (2025-06-17) ---

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) { 
        int n=nums.size();
        int maxlen=INT_MIN,len=INT_MIN;
        int flips=0;
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
                    // i ko just uske aage wale ek index se aage le jao
                    while(nums[i]==1) i++;// after this nums[i]=0
                    i++;
                    j++;
                }

            }

        }
        len=j-i;
        maxlen=max(maxlen,len);
        return maxlen;
        
    }
}; 
