// 0107. Binary Tree Level Order Traversal II [Medium]
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
//
// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).
//
//
//
// Example 1:
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
//
// Example 2:
//
// Input: root = [1]
// Output: [[1]]
//
// Example 3:
//
// Input: root = []
// Output: []
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [0, 2000].
//
// 	- -1000 <= Node.val <= 1000

// --- First accepted solution (2026-08-14) ---

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
    int level(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    void traversal(vector<vector<int>> &ans,TreeNode* root,int lev){
        if(root == NULL) return;
        traversal(ans,root->left,lev+1);
        traversal(ans,root->right,lev+1);
        ans[lev].push_back(root->val);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        int lev = level(root);
        for(int i=1;i<=lev;i++){
            vector<int> v;
            ans.push_back(v);
        }
        traversal(ans,root,0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
