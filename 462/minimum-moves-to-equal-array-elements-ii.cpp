#include "../utils.cpp"

class Solution {
public:
    int minMoves2(vector<int>& nums) {
    int n = nums.size();
    if (!n) return n;
    sort(nums.begin(), nums.end());
    int out = 0;
    for (int i = 0; i < (n / 2); ++i) {
        out -= nums[i];
    }
    if (!(n % 2)) out += nums[n / 2];
    for (int i = (n / 2) + 1; i < n; ++i) {
        out += nums[i];
    }    
    return out;
    }
};