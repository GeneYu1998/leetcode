#include <vector>
using std::vector;

class Solution {
public:
    int target;
    void binary_search(const vector<int>& nums, const int& lower, const int& upper)
    {    
        if (upper != lower) 
        {
            int mid = (int)(lower + upper) / 2;
            if (nums[mid] != mid)  binary_search(nums, lower, mid);
            else binary_search(nums, mid + 1, upper);
        }
        else
        {
            target = (nums[lower]>lower)?nums[lower]-1:nums[lower]+1;
            return;
        }
    } 

    int missingNumber(vector<int>& nums) { 
    binary_search(nums, 0, (int)(nums.size() - 1));
    return target;
    }
};