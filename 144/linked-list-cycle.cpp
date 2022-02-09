#include "..\utils.cpp"

class Solution {
public:
    ListNode* fast;
    bool hasCycle(ListNode *head) {
    fast = head;
    while(fast && head)
    {   
        fast = fast->next?fast->next->next:nullptr;
        head = head->next;
        if(fast && head && fast == head) return true;
    }        
    return false;
    }
};