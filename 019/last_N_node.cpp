struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int cnt = 1;
    int call_back = 0;

    void removeNth(ListNode* temp, int n) { 
            if(temp->next)
            {   
                ++cnt;
                removeNth(temp->next, n);
            }
            ++call_back;
            if (call_back == n + 1) temp->next = temp->next->next;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {  
            removeNth(head, n);
            if (cnt == n) head = head->next;          
            return head;
    }
};