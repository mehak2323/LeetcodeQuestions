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
    
    //To find depth/height, O(n)
    int find_height(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+max(find_height(root->left),find_height(root->right));
    }
    
    //Given function
    bool isBalanced(TreeNode* root) {
        
        //For 0 height, tree is balanced
        if(root==nullptr) return true;
        
        //Find max heights of left and right subtree
        int lh = find_height(root->left);
        int rh = find_height(root->right);
        
        //If their difference is more than 1, unbalanced
        if(abs(lh-rh)>1) return false;
        
        //If current node balanced by above condition and 
        //left and right subtree also balanced, tree is balanced
        if(isBalanced(root->left) && isBalanced(root->right))
            return true;
        
        return false;
    }
};