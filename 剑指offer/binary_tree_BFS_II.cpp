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
    vector<vector<int>> nodes;
    queue<TreeNode*> node_queue;
    TreeNode* node;
    vector<vector<int>> levelOrder(TreeNode* root) {
    int this_level_cnt = 0, next_level_cnt=0, adds = 0;
    vector<int> this_level;
    if (root) 
    {
        node_queue.push(root);
        ++this_level_cnt;
    }
    while(!node_queue.empty())
    {   

        node = node_queue.front();
        this_level.push_back(node->val);
        ++adds;
        node_queue.pop();

        if(node->left) 
        {
            node_queue.push(node->left);
            ++next_level_cnt;
        }
        if(node->right) 
        {
            node_queue.push(node->right);
            ++next_level_cnt;
        }

        if (adds == this_level_cnt)
        {   
            nodes.push_back(this_level);
            this_level.clear();
            adds = 0;
            this_level_cnt = next_level_cnt;
            next_level_cnt = 0;
        }
    }
    return nodes;
    }
};