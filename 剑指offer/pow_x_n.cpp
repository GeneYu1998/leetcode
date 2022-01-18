class Solution {
public:

    double myPow(double x, int n) {
    if (n==0 || x==1) return 1;
    else if (n < 0) return 1 / (quickPow(x, 1, -(n + 1)) * x);
    else return quickPow(x, 1, n);
    }

    inline double quickPow(const double& x, const double& t, const unsigned int& n){   
        return n?quickPow(x * x, (n & 1)?x * t:t, n >> 1):t;   
    }
};