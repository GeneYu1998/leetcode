#include<algorithm>
using std::swap;

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void swap_left_right(TreeNode* node)
    {
        if(node->left && node->right)
        {
            swap(node->left, node->right);
            swap_left_right(node->left);
            swap_left_right(node->right);
        }
        else if(node->left)
        {
            node->right = node->left;
            node->left = nullptr;
            swap_left_right(node->right);
        }
        else if(node->right)
        {
            node->left = node->right;
            node->right = nullptr;
            swap_left_right(node->left);            
        }
    }
    TreeNode* mirrorTree(TreeNode* root) {
    if(root) swap_left_right(root);
    return root;
    }
};