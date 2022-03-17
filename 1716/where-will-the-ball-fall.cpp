#include "..\utils.cpp"

class Solution {
public:
    int balldfs(vector<vector<int>>& grid, const int& i, const int& j, const int& m, const int& n)
    {   
        if(i == m) return j; // a success falling (legal)
        else if(grid[i][j] == 1)
        {
            if(j == n - 1 || grid[i][j + 1] == -1) return -1; // exceed right horizontal boundary or stuck on right (illegal)
            else return balldfs(grid, i + 1, j + 1, m, n);
        }
        else if(grid[i][j] == -1)
        {
            if(j == 0 || grid[i][j - 1] == 1) return -1; // exceed left horizontal boundary or stuck on left (illegal)
            else return balldfs(grid, i + 1, j - 1, m, n);            
        }
        return -1;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> ans;
    for(int j = 0; j < n; ++j) ans.emplace_back(balldfs(grid, 0, j, m, n));
    return ans;
    }
};