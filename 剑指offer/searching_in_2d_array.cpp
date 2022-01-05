#include <vector>
using std::vector;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int n = matrix.size(), m = matrix[0].size();
    int i = 0, j = m - 1, this_value; // staring at upper-right
    while(i!=n && j!=-1)
    {   
        this_value = matrix[i][j];
        if(this_value == target) return true;
        else if(this_value > target) --j;
        else ++i;
    }
    return false;
    }
};