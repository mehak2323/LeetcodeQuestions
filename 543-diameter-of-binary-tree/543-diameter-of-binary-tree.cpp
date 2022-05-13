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
    
//     int diameterOfBinaryTree2(TreeNode* root) {
        
//         if(root==nullptr) return 0;
        
//         int lh = diameterOfBinaryTree2(root->left);
//         int rh = diameterOfBinaryTree2(root->right);
        
//         return max(1+max(lh,rh),1+lh+rh);
//     }
    
    int diameterOfBinaryTreeRecur(TreeNode* root, int &ans) {
        
        if(root==nullptr) return 0;
        
        int lh = diameterOfBinaryTreeRecur(root->left,ans);
        int rh = diameterOfBinaryTreeRecur(root->right,ans);
        
        int curr_max = lh+rh;
        
        if(ans<curr_max)
            ans=curr_max;
            
        return 1+max(lh,rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        int ans=0;
        int temp = diameterOfBinaryTreeRecur(root, ans);
        return ans;
    }
    
};