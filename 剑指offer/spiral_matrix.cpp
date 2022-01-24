#include <vector>
using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    int m = matrix.size();
    if(m == 0) return ans;
    if(m == 1) return matrix[0];
    int n = matrix[0].size();
    int l = 0, r = n - 1, u = 0, b = m - 1;
    int i, j;
    while(l < r || u < b)
    {      
        ans.push_back(matrix[u][l]);
        for(j = l + 1; j < r; j++) ans.push_back(matrix[u][j]); //up
        if(l != r) ans.push_back(matrix[u][r]);
        for(i = u + 1; i < b; i++) ans.push_back(matrix[i][r]); //right
        if(b != u) ans.push_back(matrix[b][r]);
        if(b != u) for(j = r - 1; j > l; j--) ans.push_back(matrix[b][j]); //down
        if(b != u && l != r) ans.push_back(matrix[b][l]);
        if(l != r) for(i = b - 1; i > u; i--) ans.push_back(matrix[i][l]); //left

        // alter BCs
        ++l;
        --r;
        ++u;
        --b;

        if(l > r || u > b) break;
    }
    if(m == n && (m & 1)) ans.push_back(matrix[n/2][n/2]); //center element
    return ans;
    }
};