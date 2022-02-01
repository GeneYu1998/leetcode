#include <vector>
using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int n = nums.size();
    if (n == 0) return 0;
    int pt = 0, rt = pt;
    while(rt != n)
    {
        while(rt != n && nums[rt] == val) rt++;
        if(rt != n) nums[pt++] = nums[rt++];
    }
    return pt;
    }
};