// 0889. Construct Binary Tree from Preorder and Postorder Traversal [Medium]
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
//
// Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
//
// If there exist multiple answers, you can return any of them.
//
//
//
// Example 1:
//
// Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
//
// Example 2:
//
// Input: preorder = [1], postorder = [1]
// Output: [1]
//
//
//
// Constraints:
//
// 	- 1 <= preorder.length <= 30
//
// 	- 1 <= preorder[i] <= preorder.length
//
// 	- All the values of preorder are unique.
//
// 	- postorder.length == preorder.length
//
// 	- 1 <= postorder[i] <= postorder.length
//
// 	- All the values of postorder are unique.
//
// 	- It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.

// --- First accepted solution (2025-07-10) ---


class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int preL, int preH, vector<int>& postorder, int postL, int postH) {
        if (preL > preH) return nullptr;

        TreeNode* root = new TreeNode(preorder[preL]);
        if (preL == preH) return root;

        // Next node in preorder is the left child
        int leftRootVal = preorder[preL + 1];
        
        // Find leftRootVal in postorder to determine left subtree size
        int i = postL;
        while (i <= postH && postorder[i] != leftRootVal) i++;
        int leftCount = i - postL + 1;

        // Recursively build left and right subtrees
        root->left = helper(preorder, preL + 1, preL + leftCount, postorder, postL, postL + leftCount - 1);
        root->right = helper(preorder, preL + leftCount + 1, preH, postorder, postL + leftCount, postH - 1);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return helper(preorder, 0, n - 1, postorder, 0, n - 1);
    }
};
