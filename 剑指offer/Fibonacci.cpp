class Solution {
public:
    int fib(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else
    {
    int prev = 1;
    int prev_2 = 0;
    int this_one;  
    for (int i = 1; i < n; ++i)
    {   
        // passing the time steps backward for the 2nd difference equation.
        this_one = (prev + prev_2) % 1000000007;
        prev_2 = prev;
        prev = this_one;
    }  
    return this_one;    
    }
    }
};