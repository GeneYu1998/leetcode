#include <vector>
#include <queue>
using std::vector;
using std::deque;

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
    deque<TreeNode*> node_queue;
    TreeNode* node;

    void add_from_left(TreeNode* node, int& next_level_cnt)
    {
        if(node->left)
        {
            node_queue.push_back(node->left);
            ++next_level_cnt;
        }
        if(node->right)
        {
            node_queue.push_back(node->right);
            ++next_level_cnt;
        }        
    }

    void add_from_right(TreeNode* node, int& next_level_cnt)
    {
        if(node->right)
        {
            node_queue.push_front(node->right);
            ++next_level_cnt;
        } 
        if(node->left)
        {
            node_queue.push_front(node->left);
            ++next_level_cnt;
        }     
    }


    vector<vector<int>> levelOrder(TreeNode* root) {
    int this_level_cnt = 0, next_level_cnt=0, adds = 0;
    vector<int> this_level;
    bool from_left = true;
    if (root) 
    {
        node_queue.push_back(root);
        ++this_level_cnt;
    }
    while(!node_queue.empty())
    {   
        // if mark as 'from left', we add the results from this level from left to right, also add the children from left to right.
        if (from_left)
        {
            node = node_queue.front();
            this_level.push_back(node->val);
            node_queue.pop_front();    
            add_from_left(node, next_level_cnt); 
        }
        // if mark as 'from right', we add the results from this level from right to left, also add the children from right to left.
        else
        {
            node = node_queue.back();
            this_level.push_back(node->val);
            node_queue.pop_back();
            add_from_right(node, next_level_cnt);       
        }

        ++adds;

        if (adds == this_level_cnt)
        {   
            nodes.push_back(this_level);
            this_level.clear();
            adds = 0;
            this_level_cnt = next_level_cnt;
            next_level_cnt = 0;
            from_left = !from_left;
        }
    }
    return nodes;
    }
};