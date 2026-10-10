// 2385. Amount of Time for Binary Tree to Be Infected [Medium]
// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
//
// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
//
// Each minute, a node becomes infected if:
//
// 	- The node is currently uninfected.
//
// 	- The node is adjacent to an infected node.
//
// Return the number of minutes needed for the entire tree to be infected.
//
//
//
// Example 1:
//
// Input: root = [1,5,3,null,4,10,6,9,2], start = 3
// Output: 4
// Explanation: The following nodes are infected during:
// - Minute 0: Node 3
// - Minute 1: Nodes 1, 10 and 6
// - Minute 2: Node 5
// - Minute 3: Node 4
// - Minute 4: Nodes 9 and 2
// It takes 4 minutes for the whole tree to be infected so we return 4.
//
// Example 2:
//
// Input: root = [1], start = 1
// Output: 0
// Explanation: At minute 0, the only node in the tree is infected so we return 0.
//
//
//
// Constraints:
//
// 	- The number of nodes in the tree is in the range [1, 105].
//
// 	- 1 <= Node.val <= 105
//
// 	- Each node has a unique value.
//
// 	- A node with a value of start exists in the tree.

// --- First accepted solution (2025-07-13) ---


class Solution {
public:
// amountOfTime is basically equal to levels in (deformed) tree from the perspective of given infected node
    TreeNode* begin=NULL;
    void find(TreeNode* root, int start){
        if(root == NULL) return ; 
        if(root->val == start){
             begin=root;
             return;
        }
        find(root->left,start);
        find(root->right,start);
    } 
    void markparent(TreeNode* root,unordered_map<TreeNode* , TreeNode*> &parent ){
        if(root ==NULL) return;
        if(root->left !=NULL) parent[root->left] = root;
        if(root->right !=NULL) parent[root->right] = root;
        markparent(root->left,parent);
        markparent(root->right,parent);
    }
    int amountOfTime(TreeNode* root, int start) {
        // step 1: find the node for start value;
        find(root,start);
        // step 2: Mark the parent Node using hasmap
        unordered_map<TreeNode* , TreeNode*>parent;
        markparent(root,parent);

        unordered_set <TreeNode* > Isinfected;
        Isinfected.insert(begin);

        queue <pair <TreeNode* , int> > q;
        q.push({begin,0});

        // step 3: Breadth first search(BFS)
        int maxlevel=0;
        while(q.size()>0){
            pair <TreeNode* , int> p = q.front();
            q.pop();
            int level  = p.second;
            maxlevel = max(maxlevel,level);
            TreeNode* temp = p.first;
            if(temp->left != NULL){
                if(Isinfected.find(temp->left) == Isinfected.end()){// nhi hai
                    q.push({temp->left,level+1});
                    Isinfected.insert(temp->left);
                }
            }
            if(temp->right != NULL){
                if(Isinfected.find(temp->right) == Isinfected.end()){// nhi hai
                    q.push({temp->right,level+1});
                    Isinfected.insert(temp->right);
                }
            }
            if(parent.find(temp) != parent.end()){
                 if(Isinfected.find(parent[temp]) == Isinfected.end()){// nhi hai
                    q.push({parent[temp],level+1});
                    Isinfected.insert(parent[temp]);
                 }
            }
        }
        return  maxlevel;

        
    }
};
