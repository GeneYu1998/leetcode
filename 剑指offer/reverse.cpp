
// Definition for singly-linked list.
struct ListNode {
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* tail=nullptr;

    void reverse(ListNode* temp)
    {    
         if (!temp) return;

         if(temp->next)
         {
            reverse(temp->next);
            if(temp->next == tail) tail->next = temp;
            else temp->next->next = temp;           
         }
         else tail = temp;
    }

    ListNode* reverseList(ListNode* head) {
    reverse(head);
    if(head) head->next = nullptr;
    return tail;
    }
};