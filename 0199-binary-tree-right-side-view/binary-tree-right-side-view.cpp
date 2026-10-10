// 0199. Binary Tree Right Side View [Medium]
// https://leetcode.com/problems/binary-tree-right-side-view/
//
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//
//
// Example 1:
//
// Input: root = [1,2,3,null,5,null,4]
//
// Output: [1,3,4]
//
// Explanation:
//
// Example 2:
//
// Input: root = [1,2,3,4,null,null,null,5]
//
// Output: [1,3,4,5]
//
// Explanation:
//
// Example 3:
//
// Input: root = [1,null,3]
//
// Output: [1,3]
//
// Example 4:
//
// Input: root = []
//
// Output: []
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [0, 100].
//
// 	- -100 <= Node.val <= 100

// --- First accepted solution (2025-07-10) ---


class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    void nthlevel(TreeNode* root,int cur,int req,vector<int> &ans){
        if(root == NULL) return;
        if(cur == req){
            ans[cur]=root->val;
            return;
        }
        nthlevel( root->left, cur+1, req,ans);
        nthlevel( root->right, cur+1, req,ans);
    }
    void levelorder(TreeNode* root,vector<int> &ans){
        int n=ans.size();
        for(int i=0;i<n;i++){
            nthlevel(root,0,i,ans);
            
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        int n =level(root);
        vector<int> ans(n,0);
        levelorder(root,ans);
        return ans;
    }
    
};
