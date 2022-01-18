#include <algorithm>

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
    int depth;

    void search_Depth(TreeNode* node, int this_depth)
    {   
        ++this_depth;
        if(!node->left && !node->right) depth = std::max(depth, this_depth);
        if(node->left) search_Depth(node->left, this_depth);
        if(node->right) search_Depth(node->right, this_depth); 
    }

    int maxDepth(TreeNode* root) {
    depth = 0;
    if (!root) return depth;
    else 
    {
        search_Depth(root, depth);
        return depth;
    }
    }
};