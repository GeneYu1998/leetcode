#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            int remain = target - nums[i];
            auto it = hashtable.find(remain);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    auto nums = vector<int>{2, 7, 11, 15, 20, 40, 50, 30, 10, 80, 120, 130};
    int target = 100;
    auto sols = Solution().twoSum(nums, target);
    cout << '[';
    for(const auto sol: sols)
    {
        cout << sol;
        if (sol!= sols.back()) cout << ", ";
    }
    cout << ']';
}