#include "..\utils.cpp"

class Solution {
public:
    vector<int> output;

    void inorderTraversal_DFS(TreeNode* node)
    {   
        if(!node) return;

        inorderTraversal_DFS(node->left); //first insert left-son
        output.push_back(node->val); //then insert this node
        inorderTraversal_DFS(node->right); //last insert right-son
    }

    vector<int> inorderTraversal(TreeNode* root) {
    inorderTraversal_DFS(root);
    return output;
    }
};