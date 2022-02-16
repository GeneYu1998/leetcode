#include "..\utils.cpp"

class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size();
    int cur = 0, prev = cur;
    for(int i = 0; i < n; ++i)
    {   
        nums[i] += prev;
        prev = cur;
     cur = max(nums[i], cur);
    }
    return cur;
    }
};