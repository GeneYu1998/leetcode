#include <queue>
using std::queue;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
public:
    
    void judge_SubStructure(TreeNode* A, TreeNode* B, bool& valid)
    {    
         if (!valid) return;
         else if (A->val != B->val)
         {
            valid = false;
            return;            
         }
         else if ((!A->left && B->left) || (!A->right && B->right)) 
         {
            valid = false;
            return;
         }
         else
         {  
            if (A->left && B->left) judge_SubStructure(A->left, B->left, valid);
            if (A->right && B->right) judge_SubStructure(A->right, B->right, valid);
         }
    }
    
    bool isSubStructure(TreeNode* A, TreeNode* B) {
    queue<TreeNode*> node_queue;
    TreeNode* node;
    bool valid=false;
    if (!A || !B) return false;
    else
    {   
        node_queue.push(A);
        while(!node_queue.empty())
        {
            node = node_queue.front();
            if (node->val == B->val) 
            {
                valid = true;
                judge_SubStructure(node, B, valid);
                if (valid) break;
            }
            node_queue.pop();
            if(node->left) node_queue.push(node->left);
            if(node->right) node_queue.push(node->right);
        }
        return valid;
    }
    }
};