#include "..\utils.cpp"

class Solution {
public:
    int subarray_max;
    int this_index_ending_max;

    int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    this_index_ending_max = nums[0];
    subarray_max = nums[0];    
    for(int i = 1; i < n; ++i)
    {
        this_index_ending_max = (this_index_ending_max < 0)?nums[i]:this_index_ending_max + nums[i];
        subarray_max = max(subarray_max, this_index_ending_max);
    }
    return subarray_max;
    }
};