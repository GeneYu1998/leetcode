
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    bool add_left = (list1 && !list2) || (list1 && list2 && list1->val <= list2->val);
    auto cur = add_left?list1:list2;
    if(!cur) return nullptr;
    list1 = add_left?list1->next:list1;
    list2 = add_left?list2:list2->next;
    ListNode* new_head = cur;
    while (list1 || list2)
    {
    add_left = (list1 && !list2) || (list1 && list2 && list1->val <= list2->val);
    cur->next = add_left?list1:list2;
    list1 = add_left?list1->next:list1;
    list2 = add_left?list2:list2->next;
    cur = cur->next;
    }
    return new_head;
    }
};