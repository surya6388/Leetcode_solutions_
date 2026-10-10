// 0103. Binary Tree Zigzag Level Order Traversal [Medium]
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
//
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
//
//
//
// Example 1:
//
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
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
// 	- -100 <= Node.val <= 100

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
        if(root == NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }
    void Nthlevel(TreeNode* root,int cur,int req,vector<int> &v){
        if(root == NULL) return ;
        if(cur == req){
            v.push_back(root->val);
            return;
        }
        Nthlevel(root->left,cur+1,req,v);
        Nthlevel(root->right,cur+1,req,v);
    }
    void reverselevel(TreeNode* root,int cur,int req,vector<int> &v){
        if(root == NULL) return ;
        if(cur == req){
            v.push_back(root->val);
            return;
        }
        reverselevel(root->right,cur+1,req,v);
        reverselevel(root->left,cur+1,req,v);
    }
    void order(TreeNode* root,vector<vector<int>>& ans){
        int n=level(root);
        for(int i=1;i<=n;i++){
            vector<int> v;
            if(i%2==0) reverselevel(root,1,i,v);
            else Nthlevel(root,1,i,v);
            ans.push_back(v);
            cout<<endl;
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        order(root,ans);
        return ans;
        
    }
};
