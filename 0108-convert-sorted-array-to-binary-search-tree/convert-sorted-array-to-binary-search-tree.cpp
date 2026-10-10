// 0108. Convert Sorted Array to Binary Search Tree [Easy]
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
//
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
//
//
//
// Example 1:
//
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:
//
// Example 2:
//
// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.
//
//
//
// Constraints:
//
// 	- 1 <= nums.length <= 104
//
// 	- -104 <= nums[i] <= 104
//
// 	- nums is sorted in a strictly increasing order.

// --- First accepted solution (2025-07-11) ---


class Solution {
public:
    TreeNode* helper(vector<int>& arr,int low,int high){
        if(low > high) return NULL;
        int mid = low + (high-low)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = helper(arr,low, mid-1);
        root->right =  helper(arr,mid+1,high);
        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        int n= arr.size();
        return helper(arr,0, n-1);
    }
};
