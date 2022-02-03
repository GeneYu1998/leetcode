// Definition for singly-linked list.
struct ListNode {
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//Definition for double-linked list.
struct DoubleListNode {
    DoubleListNode *next; 
    DoubleListNode *prev;
    int val;
    int key;
    DoubleListNode() : key(0), val(0), next(nullptr), prev(nullptr)  {}
    DoubleListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    DoubleListNode(int x, int y, DoubleListNode *next) : key(x), val(y), next(next), prev(nullptr) {}
    DoubleListNode(int x, int y, DoubleListNode *next, DoubleListNode *prev) : key(x), val(y), next(next), prev(prev) {}
};

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode* left;
     TreeNode* right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };