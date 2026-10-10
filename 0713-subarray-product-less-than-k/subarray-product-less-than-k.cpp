// 0713. Subarray Product Less Than K [Medium]
// https://leetcode.com/problems/subarray-product-less-than-k/
//
// You are given an array of integers nums and an integer k.
//
// Return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
//
//
//
// Example 1:
//
// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
//
// Example 2:
//
// Input: nums = [1,2,3], k = 0
// Output: 0
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 3 * 104
//
// 	- 1 <= nums[i] <= 1000
//
// 	- 0 <= k <= 106

// --- First accepted solution (2025-06-18) ---

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int n=nums.size();
    if(k<=1) return 0;
    int i=0;
    int j=0;
    int p=1;
    int count=0;
    while(j<n){
        p *= nums[j];
        while(p>=k){
            count+=(j-i);
            p/=nums[i];
            i++;
        }
        j++;
    }
    while(i<n){
        count+=(j-i);
        p/=nums[i];
        i++;
    }
    return count; 

        
    }
};
