#include <vector>
using std::vector;

class Solution {
public:
    int total_grid;
    int my_mod(const int& num)
    {
        return num / 10 + num % 10;
    }

    void dfs(vector<vector<int>>& passed, const int& i, const int& j, const int& m, const int& n, const int& k)
    {   
        if (i == -1 || i == m || j == -1 || j == n || passed[i][j] == -1) return; // passed, or out of boundary
        else passed[i][j] = -1;

        if (my_mod(i) + my_mod(j) > k) return;
        else ++total_grid;

        // DFS in the neighborhood
        dfs(passed, i+1, j, m, n, k); //down
        dfs(passed, i, j+1, m, n, k); //right
        dfs(passed, i, j-1, m, n, k); //left
        dfs(passed, i-1, j, m, n, k); //up
    }

    int movingCount(int m, int n, int k) {
    vector<vector<int>> passed(m, vector<int>(n, 0));
    dfs(passed, 0, 0, m, n, k);
    return total_grid;
    }
};