#include "..\utils.cpp"

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
    int MinRooms = 1;
    sort(intervals.begin(), intervals.end(), [&](vector<int> itv_1, vector<int> itv_2){return itv_1[0] < itv_2[0];});
    vector<int> ends = {intervals[0][1]};
    for(int i = 1; i < intervals.size(); ++i)
    {  
       if(intervals[i][0] < ends[0]) 
       {
          ++MinRooms;
          ends.push_back(intervals[i][1]);
       }
       else ends[0] = intervals[i][1];

       sort(ends.begin(), ends.end()); 
    }
    return MinRooms;
    }
};