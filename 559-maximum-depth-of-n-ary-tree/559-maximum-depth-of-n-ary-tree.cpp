/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        //Base case, if end reached, 0 height
        if(root==nullptr) return 0;
        
        int currMax = 0;
        
        //Find heights for child subtrees and take max of them
        for(auto itr: root->children){
            currMax = max(currMax, maxDepth(itr));
        }
        
        //Current node's 1 + maximum height of child subtrees
        return 1 + currMax;
    }
};