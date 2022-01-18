#include <vector>
#include <queue>
using std::priority_queue;
using std::vector;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct TreeNode_less{
   bool operator() (const TreeNode* l1, const TreeNode* l2) const
   {
    return l1->val < l2->val;
   }
};

class Solution {
public:
    int cur;
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNode_less> my_queue;
    void searchkth(TreeNode* node)
    {
    if (!node) return;
    else
    {   
        my_queue.push(node);
        searchkth(node->left);
        searchkth(node->right);
    }
    }

    int kthLargest(TreeNode* root, int k) {
    searchkth(root);
    int cnt = 0;
    while(++cnt!=k) my_queue.pop();
    return my_queue.top()->val;
    }
};