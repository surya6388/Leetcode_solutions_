// 0094. Binary Tree Inorder Traversal [Easy]
// https://leetcode.com/problems/binary-tree-inorder-traversal/
//
// Given the root of a binary tree, return the inorder traversal of its nodes' values.
//
//
//
// Example 1:
//
// Input: root = [1,null,2,3]
//
// Output: [1,3,2]
//
// Explanation:
//
// Example 2:
//
// Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
//
// Output: [4,2,6,5,7,1,3,9,8]
//
// Explanation:
//
// Example 3:
//
// Input: root = []
//
// Output: []
//
// Example 4:
//
// Input: root = [1]
//
// Output: [1]
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [0, 100].
//
// 	- -100 <= Node.val <= 100
//
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?

// --- First accepted solution (2025-07-08) ---

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Inorder(TreeNode* root,vector<int>& ans){//4 2 5 1 6 3 7 
    if(root == NULL) return ;//base case
    Inorder(root->left,ans);//call 1
    ans.push_back(root->val);
    Inorder(root->right,ans);// call 2
}
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Inorder(root,ans);
        return ans;
        
    }
};
