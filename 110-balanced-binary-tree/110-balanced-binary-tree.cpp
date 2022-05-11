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
    
    
    //Fuction to find max depth and update bool if depth difference more than 1, O(n)
    int find_height(TreeNode* root, bool &ans){
        
        if(root==nullptr) return 0;
        
        int lh = find_height(root->left,ans);
        int rh = find_height(root->right,ans);
        
        //Condition check to mark false, rest func same
        if(abs(lh-rh)>1) ans = false;
        
        return 1+max(lh,rh);
    }
    
    //Given function
    bool isBalanced(TreeNode* root) {
        
        bool ans = true;
        
        //Recursion and update ans if false
        int temp = find_height(root, ans);
        
        return ans;
    }
    
    /* O(n^2 solution)
    
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
    */
};