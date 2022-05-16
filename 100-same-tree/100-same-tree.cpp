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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        //If any tree reaches end
        if(p==nullptr || q==nullptr){
            //If both are not at end, false
            if(p!=q) return false;
            return true;
        }
        
        //Checks for node same, left subtree same and right subtree same
        bool curr_node = p->val == q->val;
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        
        if(left && right && curr_node) return true;
        return false;
    }
};