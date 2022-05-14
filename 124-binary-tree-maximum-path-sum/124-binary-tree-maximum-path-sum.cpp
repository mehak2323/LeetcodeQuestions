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

    int maxPathSumRecur(TreeNode* root, int &ans) {
        //If null/end reached, no sum
        if(root==nullptr) return 0;
        
        //Find max sums from left and right subtree
        int lsum = max(maxPathSumRecur(root->left,ans), 0);
        int rsum = max(maxPathSumRecur(root->right,ans), 0);
        
        //Update ans with max of- added root path, left path, right path, node itself
        //ans = max(ans, max(root->val,max(lsum+rsum+root->val, max(lsum, rsum)+root->val)));
        ans = max(ans, lsum+rsum+root->val);
        
        //Return bigger of the left and right sum as one path is taken at a time
        return max(lsum,rsum)+root->val;
    }
    
    ///Given
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathSumRecur(root, ans);
        return ans;
    }
};