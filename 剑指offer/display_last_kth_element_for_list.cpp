// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode* next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
    int cnt = 0;
    ListNode* pt_1 = head;
    while((++cnt)!= k) pt_1 = pt_1->next; // dispatch the fast pointer.
    while(pt_1->next) // slow pointer goes together with the fast pointer. 
    {
        pt_1 = pt_1->next;
        head = head->next;
    }
    return head;
    }
};