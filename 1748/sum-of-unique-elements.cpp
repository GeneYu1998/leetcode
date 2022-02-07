#include "..\utils.cpp"

class Solution {
public:
    unordered_map<int, int> cache;

    int sumOfUnique(vector<int>& nums) {
    int out = 0;
    for(auto& num: nums)
    {   
        if(!cache.count(num))
        {
           out += num;
           cache.insert(make_pair(num, 0));
        }
        else if(!cache[num]++) out -= num;
        else cache[num]++;
    }
    return out;
    }
};