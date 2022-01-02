#include <queue>
using std::deque;


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    deque<TreeNode*> front_queue;
    deque<TreeNode*> back_queue;
    int children_front_left=0, children_front_right=0, children_back_left=0, children_back_right=0;

    void push_child_for_front(TreeNode* front)
    {
        if(front->left) 
        {
          front_queue.push_back(front->left);
          ++children_front_left; 
        }
        if(front->right) 
        {
          front_queue.push_back(front->right);
          ++children_front_right;   
        }
    }
    void push_child_for_back(TreeNode* back)
    {
        if(back->right) 
        {
          back_queue.push_front(back->right);  
          ++children_back_right;
        }
        if(back->left) 
        {
          back_queue.push_front(back->left);  
          ++children_back_left;
        }

    }

    bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    else
    {  
       if (root->left && root->right)
       {
          front_queue.push_back(root->left);
          back_queue.push_front(root->right); 
       }
       else if (!root->left && !root->right) return true;
       else return false;
    }

    TreeNode* front;
    TreeNode* back;

    while(!front_queue.empty() || !back_queue.empty())
    {   
        front = front_queue.front();
        back = back_queue.back();
        if (front->val != back->val) return false;
        push_child_for_front(front);
        front_queue.pop_front();
        push_child_for_back(back);
        back_queue.pop_back();
        if ((!front_queue.empty() && back_queue.empty()) || (front_queue.empty() && !back_queue.empty()) || (children_back_left!=children_front_right) || (children_back_right!=children_front_left)) return false;
    }  
    return true;
    }
};