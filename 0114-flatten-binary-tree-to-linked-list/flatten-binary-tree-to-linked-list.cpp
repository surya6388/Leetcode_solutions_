// 0114. Flatten Binary Tree to Linked List [Medium]
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
//
// Given the root of a binary tree, flatten the tree into a "linked list":
//
// 	- The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//
// 	- The "linked list" should be in the same order as a pre-order traversal of the binary tree.
//
//
//
// Example 1:
//
// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
//
// Example 2:
//
// Input: root = []
// Output: []
//
// Example 3:
//
// Input: root = [0]
// Output: [0]
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [0, 2000].
//
// 	- -100 <= Node.val <= 100
//
//
//
// Follow up: Can you flatten the tree in-place (with O(1) extra space)?

// --- First accepted solution (2025-07-11) ---


class Solution {
public:
    vector<TreeNode*> pre(TreeNode* root,vector<TreeNode*> &ans){
        if(root==NULL) return ans ;
        ans.push_back(root);
        pre(root->left,ans);
        pre(root->right,ans);
        return ans;
    }
    void flatten(TreeNode* root) {
    vector<TreeNode*> ans;
    pre(root,ans);
    int n= ans.size();
    for(int i=0;i<n-1;i++){
        ans[i]->right = ans[i+1];
        ans[i]->left = NULL;
    }
    }
};
