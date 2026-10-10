// 1008. Construct Binary Search Tree from Preorder Traversal [Medium]
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
//
// Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
//
// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
//
// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
//
// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.
//
//
//
// Example 1:
//
// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]
//
// Example 2:
//
// Input: preorder = [1,3]
// Output: [1,null,3]
//
//
//
// Constraints:
//
// 	- 1 <= preorder.length <= 100
//
// 	- 1 <= preorder[i] <= 1000
//
// 	- All the values of preorder are unique.

// --- First accepted solution (2025-07-11) ---


class Solution {
public:
    void insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return ;
        else if(root->val > val) {// go left
            if(root->left == NULL){// attach it there
                root->left = new TreeNode(val);
               
            }
            else  insertIntoBST(root->left, val);
        }
        else{// go right
            if(root->right == NULL){// attach it there
                root->right = new TreeNode(val);

            }
            else insertIntoBST(root->right, val);
        }
  
    }
    TreeNode* bstFromPreorder(vector<int>& pre) {
        TreeNode* root =new TreeNode(pre[0]);
        for(int i=1;i< pre.size();i++){
            insertIntoBST(root,pre[i]);

        }
        return root;
    }
};
