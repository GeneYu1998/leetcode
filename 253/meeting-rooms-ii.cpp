#include "..\utils.cpp"

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [&](vector<int> itv_1, vector<int> itv_2){return itv_1[0] < itv_2[0];});
    vector<int> ends = {intervals[0][1]};
    for(int i = 1; i < intervals.size(); ++i)
    {  
       if(intervals[i][0] >= ends[0]) // pop smallest end time.
       {   
           pop_heap(ends.begin(), ends.end(), greater<int>());
           ends.pop_back();
       }

       ends.push_back(intervals[i][1]); // always insert the new ending time.
       push_heap(ends.begin(), ends.end(), greater<int>()); 
    }
    return ends.size();
    }
};