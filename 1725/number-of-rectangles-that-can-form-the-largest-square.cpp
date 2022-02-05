#include"..\utils.cpp"

class Solution {
public:
    int maxlen, max_edge, this_edge;
    int countGoodRectangles(vector<vector<int>>& rectangles) {
    max_edge = 0;
    for(int i = 0; i < rectangles.size(); ++i)
    {
       this_edge = rectangles[i][0] < rectangles[i][1]?rectangles[i][0]:rectangles[i][1];
       if(this_edge > max_edge)
       {
           maxlen = 1;
           max_edge = this_edge;
       }
       else if(this_edge == max_edge) maxlen++;
    }
    return maxlen;

    }
};