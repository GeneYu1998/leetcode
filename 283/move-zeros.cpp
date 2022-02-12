#include "..\utils.cpp"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int lp = 0, rp;
    while(lp < n && nums[lp]) lp++; //first zero pos;
    if(lp >= n - 1) return; //no zeros
    rp = lp + 1;
    while(rp < n)
    {
        while(rp < n && !nums[rp]) rp++;
        if(rp > n - 1) break;
        swap(nums[lp++], nums[rp++]); 
    }
    }
};