// 0102. Binary Tree Level Order Traversal [Medium]
// https://leetcode.com/problems/binary-tree-level-order-traversal/
//
// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
//
//
//
// Example 1:
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
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

// --- First accepted solution (2025-07-09) ---

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
    if(root==NULL) return 0;
    return 1 + max(level(root->left),level(root->right));
}
    void Anylevel(TreeNode* root,int curlev,int Reqlev,vector<int> &v){
        if(root == NULL) return;
        if(curlev == Reqlev){
            v.push_back(root->val);
            return ;
        }
        Anylevel(root->left,curlev+1,Reqlev,v);
        Anylevel(root->right,curlev+1,Reqlev,v);
    }
    void Order(TreeNode* root,vector<vector<int>> &ans){
        int n=level(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            Anylevel(root,1, i,v);
            ans.push_back(v);
            cout<<endl;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        Order(root,ans);
        return ans;
        
    }
}; 
