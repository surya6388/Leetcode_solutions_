// 0098. Validate Binary Search Tree [Medium]
// https://leetcode.com/problems/validate-binary-search-tree/
//
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//
// A valid BST is defined as follows:
//
// 	- The left subtree of a node contains only nodes with keys strictly less than the node's key.
//
// 	- The right subtree of a node contains only nodes with keys strictly greater than the node's key.
//
// 	- Both the left and right subtrees must also be binary search trees.
//
//
//
// Example 1:
//
// Input: root = [2,1,3]
// Output: true
//
// Example 2:
//
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [1, 104].
//
// 	- -231 <= Node.val <= 231 - 1

// --- First accepted solution (2025-07-11) ---


class Solution {
public:
    long long maxLST(TreeNode* root){
        if(root==NULL) return LLONG_MIN;
        return max((long long)(root->val),max(maxLST(root->left),maxLST(root->right)));
    }
    long long minRST(TreeNode* root){
        if(root==NULL) return LLONG_MAX;
        return min((long long)(root->val),min(minRST(root->left),minRST(root->right)));
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        else if(root->left==NULL && root->right==NULL) return true;
        else if((long long)(root->val) <= maxLST(root->left)) return false;
        else if((long long)(root->val) >= minRST(root->right)) return false;
        return (isValidBST(root->left)==true) && (isValidBST(root->right)==true);
        
    }
};
