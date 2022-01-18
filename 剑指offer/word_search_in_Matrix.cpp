#include <vector>
#include <string>
using std::string;
using std::vector;
using std::swap;

class Solution {
public:
    bool valid;
    void dfs(vector<vector<char>>& board, string& word, const int& k, const int& len, const int& i, const int& j, const int& m, const int& n) 
    {   
        if(valid || board[i][j]=='*') return;
        else if(k==len-1 && board[i][j]==word[k]) valid = true;
        else
        {   
            if(board[i][j]==word[k])
            { 
              char temp = '*';
              swap(board[i][j], temp); // marked as used
              if(i<m-1) dfs(board, word, k+1, len, i+1, j, m, n); //search down
              if(i>0) dfs(board, word, k+1, len, i-1, j, m, n); //search up
              if(j>0) dfs(board, word, k+1, len, i, j-1, m, n); //search left
              if(j<n-1) dfs(board, word, k+1, len, i, j+1, m, n); //search right
              if(!valid) swap(board[i][j], temp); //assign value back
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
    int len = word.size();
    int m = board.size();
    int n = board[0].size();
    if (len > m * n) return false;
    else
    {   
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                valid = false;
                dfs(board, word, 0, len, i, j, m, n);
                if(valid) return true;
            }
        }
        return false;
    }
    }
};