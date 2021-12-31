#include <unordered_map>

using namespace std;

//Definition for double-linked list.
struct DoubleListNode {
    DoubleListNode *next; 
    DoubleListNode *prev;
    int val;
    int key;
    DoubleListNode() : key(0), val(0), next(nullptr), prev(nullptr)  {}
    DoubleListNode(int x, int y) : key(x), val(y), next(nullptr), prev(nullptr) {}
    DoubleListNode(int x, int y, DoubleListNode *next) : key(x), val(y), next(next), prev(nullptr) {}
    DoubleListNode(int x, int y, DoubleListNode *next, DoubleListNode *prev) : key(x), val(y), next(next), prev(prev) {}
};

class LRUCache {
public:
    DoubleListNode* head;
    DoubleListNode* tail;
    DoubleListNode* Node;

    int size, erase_key;
    unordered_map<int, DoubleListNode*> _map;

    LRUCache(int capacity) {
    this->size = capacity;
    }

    void move_to_tail(DoubleListNode* Node)
    { 
      if(Node==tail);
      else if(Node==head) 
      {
        head = Node->next;
        head->prev = nullptr;
        tail->next = Node;
        Node->prev = tail;
        tail = Node;
        tail->next = nullptr;  
      }
      else
      {
        Node->prev->next = Node->next;
        Node->next->prev = Node->prev;
        tail->next = Node;
        Node->prev = tail;
        tail = Node;
        tail->next = nullptr; 
      }       
    }
    
    int get(int key) {
    if (_map.find(key)!=_map.end())
    { 
      Node = _map[key];
      move_to_tail(Node);
      return Node->val;  
    }
    else return -1;
    }
    
    void put(int key, int value) {
    auto added = new DoubleListNode(key, value);
    if (_map.empty()) 
    {   
        head = added;
        tail = added;
        head->next = tail;
        tail->prev = head;
        _map.insert(pair<int, DoubleListNode*>(key, added));
    }
    else
    {
        auto iter = _map.find(key);
        if (iter!=_map.end()) 
        {
          iter->second->val = value;
          move_to_tail(iter->second);   
        }
        else
        {
        tail->next = added;
        added->prev = tail;
        tail = added;
        if (_map.size() == size) 
        { 
          erase_key = head->key;
          head = head->next;
          head->prev = nullptr;
          delete _map[erase_key]; //clean cache on heap
          _map.erase(erase_key);  
        }
        _map.insert(pair<int, DoubleListNode*>(key, added));
        }
    }
    }
};