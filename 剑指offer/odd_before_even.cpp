#include <vector>
using std::vector;
using std::swap;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return nums;
    int p1 = 0;
    int p2 = n-1;
    while(p1!=p2)
    {
        if(nums[p1]%2==0) 
        {
          while (nums[p2]%2==0 && p2!=p1) --p2;
          if(p1 != p2) swap(nums[p1], nums[p2]);
        }
        if(p1 == p2) break;
        ++p1;
    }
    return nums;
    }
};