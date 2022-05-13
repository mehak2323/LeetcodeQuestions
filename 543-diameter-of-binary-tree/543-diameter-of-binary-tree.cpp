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
private:
    int ans=0;
    
    int diameterOfBinaryTreeRecur(TreeNode* root){
        //Base case, 0 height
        if(root == nullptr) return 0;
        
        //Find max left and right subtree heights 
        int lh = diameterOfBinaryTreeRecur(root->left);
        int rh = diameterOfBinaryTreeRecur(root->right);
        
        //If bigger diameter found, adding left and right height/edges, update
        ans = max(ans, lh+rh);
        
        //Return max height for current node
        return 1+max(lh,rh); 
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) { 
        diameterOfBinaryTreeRecur(root);
        return ans;
    }
};