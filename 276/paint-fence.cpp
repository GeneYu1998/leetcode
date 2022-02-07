class Solution {
public:
    int n1, cnt;
    int numWays(int n, int k) {
    n1 = 0, cnt = k;
    while(--n)
    {
       n1 = cnt - n1;
       cnt *= k - 1;
       cnt += n1;
    }
    return cnt;
    }
};