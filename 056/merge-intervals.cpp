#include "../utils.cpp"

class Solution {
public:
    vector<vector<int>> out;
    static inline bool sort_begin(const vector<int> inv_1, const vector<int> inv_2){return inv_1[0] < inv_2[0];}

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    out.clear();
    int n = intervals.size();
    if(!n) return out;
    sort(intervals.begin(), intervals.end(), sort_begin);
    int lp = 0;
    out.emplace_back(intervals[lp]);
    while(++lp != n)
    {   
        if(out.back()[1] >= intervals[lp][0]) out.back()[1] = max(out.back()[1], intervals[lp][1]);
        else out.emplace_back(intervals[lp]);
    }
    return out;
    }
};