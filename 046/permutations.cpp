#include "..\utils.cpp"

class Solution {
public:
    vector<vector<int>> out;
    vector<int> template_vector;

    vector<vector<int>> permute(vector<int>& nums) {
    out.emplace_back(nums);
    int n = nums.size();
    int it = n, it_2, size_out;
    for(;;)
    {
    --it; 
    size_out = out.size();
    for(int k = 0; k < size_out; ++k) 
    {   
        it_2 = n;
        while(--it_2 != it)
        {   
            template_vector = out[k];
            swap(template_vector[it_2], template_vector[it]);
            out.emplace_back(template_vector);                
        }
    }
    if(!it) break;
    }
    return out;
    }
};
