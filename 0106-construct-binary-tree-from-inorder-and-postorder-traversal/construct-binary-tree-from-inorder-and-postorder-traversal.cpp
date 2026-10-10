// 0106. Construct Binary Tree from Inorder and Postorder Traversal [Medium]
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
//
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
//
//
//
// Example 1:
//
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]
//
// Example 2:
//
// Input: inorder = [-1], postorder = [-1]
// Output: [-1]
//
//
//
// Constraints:
//
// 	- 1 <= inorder.length <= 3000
//
// 	- postorder.length == inorder.length
//
// 	- -3000 <= inorder[i], postorder[i] <= 3000
//
// 	- inorder and postorder consist of unique values.
//
// 	- Each value of postorder also appears in inorder.
//
// 	- inorder is guaranteed to be the inorder traversal of the tree.
//
// 	- postorder is guaranteed to be the postorder traversal of the tree.

// --- First accepted solution (2025-07-10) ---


class Solution {
public:
    TreeNode* helper(vector<int>& inorder, int il,int ih,vector<int>& postorder,int pl,int ph){
        if(pl>ph) return NULL;
        TreeNode* root = new TreeNode(postorder[ph]);
        if(pl==ph) return root;
        int i=il;
        while(i <= ih){
            if(inorder[i] == postorder[ph]) break;
            i++;
        }
        int leftcount = i - il;
        int rightcount = ih - i;
        root->left = helper(inorder,il,i-1, postorder , pl, pl+leftcount-1);
        root->right = helper(inorder,i+1,ih, postorder , pl+leftcount,ph-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return  helper( inorder,0 ,n-1, postorder,0 , n-1);

    }
};
