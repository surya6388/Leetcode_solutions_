// 0110. Balanced Binary Tree [Easy]
// https://leetcode.com/problems/balanced-binary-tree/
//
// Given a binary tree, determine if it is height-balanced.
//
//
//
// Example 1:
//
// Input: root = [3,9,20,null,null,15,7]
// Output: true
//
// Example 2:
//
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
//
// Example 3:
//
// Input: root = []
// Output: true
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [0, 5000].
//
// 	- -104 <= Node.val <= 104

// --- First accepted solution (2025-07-08) ---


class Solution {
public:
    int height(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;  // Empty tree is balanced

    int h1 = height(root->left);
    int h2 = height(root->right);

    // Check current node and recursively check left and right subtrees
    if(abs(h1 - h2) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    else
        return false;
}

};
