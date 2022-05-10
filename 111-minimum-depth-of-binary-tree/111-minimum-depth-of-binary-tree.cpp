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
    int minDepth(TreeNode* root) {
        //Base case if null reached, 0 height
        if(root==nullptr) return 0;
        
        //Find height of left and right subtree
        int lh = minDepth(root->left); 
        int rh = minDepth(root->right);
        
        //If not linear/skwewed tree, return 1+ min of left and right height
        if(lh!=0 && rh!=0)
            return 1+ min(lh,rh);
        //If only one height valid, return 1+ that height
        else
            return 1+max(lh,rh);
    }
};

//Tc: O(n), sc: O(n) //recursion stack
