#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack(){
    while(!mystack.empty())
    {
        mystack.pop();
    }
    while(!minstack.empty())
    {
        minstack.pop();
    }
    }
    
    void push(int x){
         mystack.push(x);
         if (minstack.empty() || x <= minstack.top()) minstack.push(x); // we keep the top() of "minstack" to be the global min.
    }
    
    void pop() {
    if (mystack.top() == minstack.top()) minstack.pop(); // Note here the elements of "minstack" is a subset of "mystack", so deleting happens simultaneously.
    mystack.pop(); // delete the supplement elements, i.e. mystack \ minstack .
    }
    
    int top() {
    return mystack.top();
    }
    
    int min() {
    return minstack.top();
    }
private:
   stack<int> mystack;
   stack<int> minstack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */