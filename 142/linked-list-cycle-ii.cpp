#include "../utils.cpp"
#include <algorithm>
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast)
    {   
        fast = fast->next?fast->next->next:nullptr;
        if(!fast) return nullptr;
        slow = slow->next;
        if(slow == fast) break;
    }
    while(head != slow) 
    {
        head = head->next;
        slow = slow->next;
    }
    return head;
    }
};

vector<int> arr;
int main()
{ 
    sort(arr.begin(), arr.end());
}