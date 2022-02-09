#include "..\utils.cpp"

class Solution {
public:
    int climbStairs(int n) {
    int prev_2 = 0, prev = 1, cur;
    while(n--)
    {
        cur = prev_2 + prev;
        prev_2 = prev;
        prev = cur;
    }
    return cur;
    }
};