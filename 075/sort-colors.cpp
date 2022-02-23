#include "..\utils.cpp"

class Solution {
public:
    void sortColors(vector<int>& nums) {
    int n = nums.size();
    int lp = 0, rp = n - 1;

    while(lp < rp)
    {
        while(nums[rp] && rp) --rp;
        while(!nums[lp] && lp != n - 1) ++lp;
        if(lp >= rp) break;
        swap(nums[lp], nums[rp]);
    }
    
    rp = n - 1;
    while(lp < rp)
    {
        while(nums[rp] == 2 && rp) --rp;
        while(nums[lp] == 1 && lp != n - 1) ++lp;
        if(lp >= rp) break;
        swap(nums[lp], nums[rp]);
    }

    }
};