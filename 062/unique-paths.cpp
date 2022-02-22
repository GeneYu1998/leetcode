#include "..\utils.cpp"

class Solution {
public:
    int uniquePaths(int m, int n) {
    if(m == 1 || n == 1) return 1;
    else
    {   
        vector<int> up(n, 1);
        vector<int> cur(n, 1);
        while(--m)
        {
            for(int i = 1; i < n; ++i) cur[i] = cur[i - 1] + up[i];
            swap(up, cur);
        }
        return up[n - 1];
    }
    }
};