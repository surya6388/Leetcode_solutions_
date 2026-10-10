// 0236. Lowest Common Ancestor of a Binary Tree [Medium]
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
//
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
//
//
//
// Example 1:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.
//
// Example 2:
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
//
// Example 3:
//
// Input: root = [1,2], p = 1, q = 2
// Output: 1
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [2, 105].
//
// 	- -109 <= Node.val <= 109
//
// 	- All Node.val are unique.
//
// 	- p != q
//
// 	- p and q will exist in the tree.

// --- First accepted solution (2025-07-08) ---


class Solution {
public:
    bool existsInTree(TreeNode* root,TreeNode* target){
        if(root == NULL) return false;
        if(root==target) return true;
        return existsInTree(root->left,target) || existsInTree(root->right,target);

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if p belongs to LST(left sub tree) and q belongs to RST then root is lowest C A
        if(root == p || root == q) return root;
        // p is  in left and q is in right
        else if(existsInTree(root->left,p) == true  && existsInTree(root->right,q) == true) return root;
        //p is in right and  q is  in left 
         else if(existsInTree(root->right,p) == true && existsInTree(root->left,q) == true) return root;
         // p and q both are in left
        else if(existsInTree(root->left,p) == true  && existsInTree(root->left,q) == true) return lowestCommonAncestor(root->left,p,q);
        else { // p and q both are in right
        return  lowestCommonAncestor(root->right,p,q);

        }

        

    }
};
