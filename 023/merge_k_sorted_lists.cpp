#include <set>
#include <vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ListNodeless{
public:
    bool operator () (const ListNode* l1, const ListNode* l2) const
    {
        return l1->val <= l2->val;
    }
};

class Solution {
public:
    set<ListNode*, ListNodeless> S;
    bool non_empty = false;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    ListNode* cur;
    ListNode* head;
    for (auto l:lists) if(l) non_empty = true;
    while(non_empty)
    {   
        non_empty = false;
        for (int i = 0; i < n; ++i)
        {   
            if(lists[i]) 
            {   
                S.insert(lists[i]);
                non_empty = true;
                lists[i] = lists[i]->next;
            }
        }
    }
    if (S.empty()) head = nullptr;
    else 
    {   
        head = *S.begin();
        cur = head;
        auto iter=S.begin();
        ++iter;
        for(;iter!=S.end(); iter++)
        {
           cur->next = *iter;
           cur = cur->next;
        }
        cur->next = nullptr;
    }  
    return head;
    }
};