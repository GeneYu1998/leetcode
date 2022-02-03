#include"..\utils.cpp"

class Solution {
public:
    ListNode* goForward(ListNode* head, int step)
    {
        while(--step)
        {
            head = head->next;
            if(!head) return head;
        }
        return head;
    }

    ListNode* reverseList(ListNode* head, ListNode* tail)
    {   
        if(!tail) return tail;

        if(head != tail) reverseList(head->next, tail)->next = head;
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* tail = goForward(head, k);
    if(tail) 
    {   
        ListNode* next_start = tail->next;
        head = reverseList(head, tail);
        head->next = next_start?reverseKGroup(next_start, k):nullptr;
        return tail;
    }
    else return head;
    }
};