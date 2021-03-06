#include "..\utils.cpp"

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(i && j) grid[i][j] += min(grid[i][j - 1], grid[i - 1][j]);
            else if(j) grid[i][j] += grid[i][j - 1];
            else if(i) grid[i][j] += grid[i - 1][j];
        }
    }
    return grid[m - 1][n - 1];
    }
};