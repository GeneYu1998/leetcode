#include "..\utils.cpp"
class Solution {
public:
    void tree2strVoid(TreeNode* node, string& out)
    {   
        out += to_string(node->val);
        if(!node->left && !node->right) return;
        out += "(";
        if(node->left) tree2strVoid(node->left, out);
        out += ")";
        if(node->right)
        {
        out += "(";
        tree2strVoid(node->right, out);
        out += ")";
        }    
    }
    string tree2str(TreeNode* root) {
    string out;
    tree2strVoid(root, out);
    return out;
    }
};