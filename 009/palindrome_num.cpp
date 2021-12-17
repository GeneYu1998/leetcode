#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0 || ((x % 10 == 0) && x!= 0)) return false;
    else
    {   
        int revert = 0;
        while(x > revert)
        {   
            revert *= 10;
            revert += x % 10;
            x /= 10;
        }
        revert = (revert > x)?revert/10:revert;
        return revert == x;
    }
    }
};