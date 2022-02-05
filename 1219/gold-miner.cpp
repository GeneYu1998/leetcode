#include "..\utils.cpp"

class Solution {
public:
    int max_profit;
    bool continue_search;
    
    // a DFS without turning-back
    bool GoldDFS(vector<vector<int>>& grid, const int& i, const int& j, const int& m, const int& n, const int objective)
    { 
        if(i == -1  || i == m || j == -1 || j == n || !grid[i][j]) return false;

        int value = grid[i][j];
        grid[i][j] = 0;
        continue_search = GoldDFS(grid, i - 1, j, m, n, objective + value);
        continue_search |= GoldDFS(grid, i, j - 1, m, n, objective + value);
        continue_search |= GoldDFS(grid, i + 1, j, m, n, objective + value);
        continue_search |= GoldDFS(grid, i, j + 1, m, n, objective + value);
        if(!continue_search) max_profit = max(max_profit, objective + value);
        grid[i][j] = value;
        return true;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
    max_profit = 0;
    int m = grid.size();
    int n = grid[0].size();
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j) if(grid[i][j]) GoldDFS(grid, i, j, m, n, 0);
    }
    return max_profit;
    }
};