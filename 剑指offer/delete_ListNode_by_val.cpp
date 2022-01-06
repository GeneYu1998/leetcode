// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNodeReCurr(ListNode* node, const int& val)
    {
        if (node->next)
        {
            if (node->next->val == val) node->next = node->next->next;
            else deleteNodeReCurr(node->next, val);
        }
    }

    ListNode* deleteNode(ListNode* head, int val) {
    if (head->val == val) head = head->next;
    else
    {
        deleteNodeReCurr(head, val);
    }
    return head;
    }
};