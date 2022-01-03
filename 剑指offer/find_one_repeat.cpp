#include <vector>
using std::vector;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
    int id;
    for (int i = 0; i < nums.size(); ++i)
    {   
        id = nums[i];
        if(i!=id && id==nums[id]) return id;
        else
        {
            nums[i] = nums[id];
            nums[id] = id;
        }
    }
    return 0;
    }
};