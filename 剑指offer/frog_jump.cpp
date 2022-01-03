class Solution {
public:
    int numWays(int n) {
    if (n == 0) return 1;
    else if (n < 3) return n;
    else
    {
        const int mod = 1000000007;
        int prev_2 = 1;
        int prev_1 = 2;
        int this_n;
        for (int i = 2; i < n; ++i)
        {
            this_n = (prev_2 + prev_1) % mod;
            prev_2 = prev_1;
            prev_1 = this_n;
        }
        return this_n;
    }
    }
};