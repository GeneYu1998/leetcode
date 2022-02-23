#include "..\utils.cpp"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* l1 = headA;
    ListNode* l2 = headB;
    while(l1 || l2)
    {   
        if(!l1) l1 = headB;
        else if(!l2) l2 = headA;
        if(l1 == l2) return l1;
        l1 = l1->next;
        l2 = l2->next;
    }    
    return nullptr;
    }
};