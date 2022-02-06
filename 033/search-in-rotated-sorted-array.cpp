#include "..\utils.cpp"

class Solution {
public:
    inline int binary_search(vector<int>& nums, const int& lb, const int& ub, const int& target)
    {   
        if(lb == ub) return nums[lb] == target?lb:-1;
        else if(lb + 1 == ub) return nums[lb] == target?lb:nums[ub] == target?ub:-1;

        int mid = (lb + ub) >> 1;
        if(nums[ub] < nums[mid]) return target >= nums[lb] && target <= nums[mid]?binary_search(nums, lb, mid, target):binary_search(nums, mid, ub, target);
        else if(nums[lb] > nums[mid])  return target <= nums[ub] && target >= nums[mid]?binary_search(nums, mid, ub, target):binary_search(nums, lb, mid, target);
        else return target <= nums[mid]?binary_search(nums, lb, mid, target):binary_search(nums, mid, ub, target);
    }

    int search(vector<int>& nums, int target) {
    return binary_search(nums, 0, nums.size() - 1, target);
    }
};

