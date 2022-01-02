#include <vector>
#include <queue>
using std::vector;
using std::queue;

 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    vector<int> nodes;
    queue<TreeNode*> node_queue;
    TreeNode* node;
    vector<int> levelOrder(TreeNode* root) {
    if (root) node_queue.push(root);
    while(!node_queue.empty())
    {   
        node = node_queue.front();
        nodes.push_back(node->val);
        node_queue.pop();
        if(node->left) node_queue.push(node->left);
        if(node->right) node_queue.push(node->right);
    }
    return nodes;
    }
};