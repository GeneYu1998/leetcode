#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <utility>

using namespace std;

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
    DoubleListNode() : val(0), next(nullptr), prev(nullptr)  {}
    DoubleListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
    DoubleListNode(int x, DoubleListNode *next) : val(x), next(next), prev(nullptr) {}
    DoubleListNode(int x, DoubleListNode *next, DoubleListNode *prev) : val(x), next(next), prev(prev) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// swap int using xor operation
void swap(int& a, int& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
}