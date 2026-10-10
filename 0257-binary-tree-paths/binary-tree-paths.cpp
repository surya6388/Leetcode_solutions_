// 0257. Binary Tree Paths [Easy]
// https://leetcode.com/problems/binary-tree-paths/
//
// You are given the root of a binary tree.
//
// Return all root-to-leaf paths in any order.
//
// A leaf is a node with no children.
//
//
//
// Example 1:
//
// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]
//
// Example 2:
//
// Input: root = [1]
// Output: ["1"]
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [1, 100].
//
// 	- -100 <= Node.val <= 100

// --- First accepted solution (2025-07-08) ---


class Solution {
public:
    void helper(TreeNode* root , string s,vector<string>& ans){
        if(root == NULL) return ;
        string a = to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            s += a;
            ans.push_back(s);
            return ;
        }
        
        helper(root->left,s + a + "->",ans);
        helper(root->right,s + a + "->",ans);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        helper(root,"",ans);
        return ans;
        
    }
}; 
