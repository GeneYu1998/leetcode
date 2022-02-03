class Solution {
public:
    int largest_Fibonacci(const int& end)
    {   
        int t = 1;
        int prev = 1, prev_2 = 1;
        while(t < end)
        {
            t = prev + prev_2;
            if(t > end) return prev;
            else if(t == end) return end;
            prev_2 = prev;
            prev = t; 
        }
        return prev;
    }

    int findMinFibonacciNumbers(int k) {
    int cnt = 0;
    while(k)
    {   
        k -= largest_Fibonacci(k);
        cnt++;
    }
    return cnt;
    }
};