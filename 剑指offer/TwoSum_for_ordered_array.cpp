#include <vector>
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size(), p1 = 0, p2 = n - 1;
    while(p1!=p2)
    {
        if (nums[p1] + nums[p2] > target) --p2;
        else if (nums[p1] + nums[p2] < target) ++p1;
        else return vector<int>{nums[p1], nums[p2]};
    }
    return vector<int>();
    }
};