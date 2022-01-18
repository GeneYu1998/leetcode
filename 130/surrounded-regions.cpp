#include <vector>
using std::vector;

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& passed, const int& i, const int& j, const int& m, const int& n)
    {   
        if (passed[i][j]==-1) return;
        else if(i==0||i==m-1||j==0||j==n-1) //BCs
        {
            passed[i][j] = -1;
        }
        else
        {   
            passed[i][j] = -1; // we mark this cell as passed
            if(board[i-1][j] == 'O') dfs(board, passed, i-1, j, m, n); // search up
            if(board[i][j-1] == 'O') dfs(board, passed, i, j-1, m, n); // search left              
            if(board[i][j+1] == 'O') dfs(board, passed, i, j+1, m, n); // search right          
            if(board[i+1][j] == 'O') dfs(board, passed, i+1, j, m, n); // search down
        }
    }

    void solve(vector<vector<char>>& board) {
    int m = board.size();
    if (m < 3) return;
    int n = board[0].size();
    if (n < 3) return;
    vector<vector<int>> passed(m, vector<int>(n, 0));

    // search BCs using dfs
    for (int j = 1; j < n-1; ++j) 
    {   
        if(board[0][j] == 'O' && board[1][j] == 'O') dfs(board, passed, 1, j, m, n);
        if(board[m-1][j] == 'O' && board[m-2][j] == 'O') dfs(board, passed, m-2, j, m, n);
    }

    for (int i = 1; i < m-1; ++i) 
    {   
        if(board[i][0] == 'O' && board[i][1] == 'O') dfs(board, passed, i, 1, m, n);
        if(board[i][n-1] == 'O' && board[i][n-2] == 'O') dfs(board, passed, i, n-2, m, n);
    }

    // substitution
    for (int i = 1; i < m - 1; ++i)
    {
        for (int j = 1; j < n - 1; ++j) 
        {   
            if(board[i][j] == 'O' && passed[i][j] == 0) board[i][j] = 'X';
        }
    }    
    }

};