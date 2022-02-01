#include <vector>
using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int t = 1, pt = 0, this_num, n = nums.size();
    if(n < 2) return n;
    this_num = nums[pt];
    while(pt != n)
    {
       while(pt != n && nums[pt] == this_num) pt++;
       if(pt == n) break;
       else 
       {
           this_num = nums[pt];
           nums[t++] = this_num;
       }
    }
    nums.erase(nums.begin() + t, nums.end());
    return t;
    }
};