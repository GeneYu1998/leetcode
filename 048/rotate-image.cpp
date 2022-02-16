#include "..\utils.cpp"

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i = 0; i < (n >> 1); ++i)
    {
        for(int j = i; j < m - i - 1; ++j)
        {
            swap(matrix[i][j], matrix[j][m - i - 1]);
            swap(matrix[i][j], matrix[n - j - 1][i]);
            swap(matrix[n - j - 1][i], matrix[n - i - 1][m - j - 1]);
        }
    }
    }
};