#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    // recursively destroy objects on heap.
    ~ListNode()
    {   
        if (this->next) this->next->~ListNode();  
        delete this;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = nullptr, *tail = nullptr;
        int carry = 0;
        while (l1 || l2) {
            int n1 = l1 ? l1->val: 0;
            int n2 = l2 ? l2->val: 0;
            int sum = n1 + n2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            l1 = l1? l1->next: nullptr;
            l2 = l2? l2->next: nullptr;
        }
        tail->next = (carry > 0)? new ListNode(carry): nullptr;
        return head;
    }
};

main()
{   
    // test case //
    auto a = new ListNode(2);
    a->next = new ListNode(4);
    a->next->next = new ListNode(3);
    auto b = new ListNode(5);
    b->next = new ListNode(6);
    b->next->next = new ListNode(4);

    auto sol = Solution().addTwoNumbers(a, b);

    cout << "a: [";
    while(a)
    {   
        cout << a->val;
        if(a->next) cout << ' ';
        a = a->next;
    }
    cout << ']' << endl;

    cout << "b: [";
    while(b)
    {   
        cout << b->val; 
        if (b->next) cout << ' ';
        b = b->next;
    }
    cout << ']' << endl;

    cout << "sum of a and b: [";

    while(sol)
    {   
        cout << sol->val;
        if (sol->next) cout << ' ';
        sol = sol->next;
    }
    cout << ']' << endl;
    
    delete a;
    delete b;
}

