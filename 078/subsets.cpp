#include "..\utils.cpp"

class Solution {
public:
    vector<vector<int>> out;

    vector<vector<int>> subsets(vector<int>& nums) {
    out.emplace_back(vector<int>{});
    int n;
    for(auto& num: nums)
    {   
        n = out.size();
        for(int k = 0; k < n; ++k) 
        {   
            out.emplace_back(vector<int>{out[k]});
            out.back().emplace_back(num);
        }
    }
    return out;
    }
};