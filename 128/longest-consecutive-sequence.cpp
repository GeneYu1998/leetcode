#include "..\utils.cpp"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    sort(nums.begin(), nums.end());
    int lp = 1, longestConsecutive = 0, len = 1, cur = nums[0];
    while(lp != n)
    {
        if(nums[lp] == cur + 1) ++len;
        else if(nums[lp] != cur)
        {
           longestConsecutive = max(longestConsecutive, len);
           len = 1; 
        }
        cur = nums[lp];
        ++lp;
    }
    longestConsecutive = max(longestConsecutive, len);
    return longestConsecutive;
    }
};