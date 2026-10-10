// 0105. Construct Binary Tree from Preorder and Inorder Traversal [Medium]
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
//
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
//
//
//
// Example 1:
//
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
//
// Example 2:
//
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
//
//
//
// Constraints:
//
// 	- 1 <= preorder.length <= 3000
//
// 	- inorder.length == preorder.length
//
// 	- -3000 <= preorder[i], inorder[i] <= 3000
//
// 	- preorder and inorder consist of unique values.
//
// 	- Each value of inorder also appears in preorder.
//
// 	- preorder is guaranteed to be the preorder traversal of the tree.
//
// 	- inorder is guaranteed to be the inorder traversal of the tree.

// --- First accepted solution (2025-07-10) ---

  
class Solution {
public:
    // pl-> preorder ka low index
    // ph-> preorder ka high index
    // il-> preorder ka low index
    // ih-> preorder ka high index
    TreeNode* build(vector<int>& pre,int pl,int ph, vector<int>& in,int il,int ih){
        if(pl>ph) return NULL;
        // finding root in Inorder which is also root of preorder
        TreeNode* root = new TreeNode(pre[pl]);
        if(pl==ph) return root;
        int i=il;
        while(i <= ih){
            if(in[i] == pre[pl]) break;
            i++;
        }
        int leftcount= i - il;
        int rightcount= ih-i;
        root->left = build(pre , pl+1 , pl+leftcount , in,il ,i-1 );
        root->right = build(pre , pl+leftcount + 1 , ph , in , i+1,ih);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        return build(pre,0,n-1,in,0,n-1);
    }
};
