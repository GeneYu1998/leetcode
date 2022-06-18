// https://leetcode.cn/problems/4ueAj6/

#include "..\utils.cpp"

class Solution {
public:
    ListNode* insert(ListNode* head, int insertVal) {
       ListNode* insertListNode = new ListNode(insertVal);
       
       // Empty LinkedList
       if (!head) {
           insertListNode->next = insertListNode;
           return insertListNode;
       }
       ListNode * node = head;

       // other situation
       while (node->next != head) {
           if ((node->val <= insertVal && node->next->val >= insertVal) ||
            (node->val > node->next->val && (node->next->val > insertVal || 
            node->val < insertVal))) break;
           node = node->next;
       }
       ListNode* next = node->next;
       node->next = insertListNode;
       insertListNode->next = next;

       return head;
    }
};