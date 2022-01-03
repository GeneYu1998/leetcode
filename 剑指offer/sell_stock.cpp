#include <vector>
using std::vector;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 0) return 0;
    int prices_min = prices[0], max_profit=0;
    for(int i = 1; i < n; ++i)
    {   
        if (prices[i] < prices_min)  prices_min = prices[i];
        else
        {
            max_profit = std::max(max_profit, prices[i] - prices_min);
        }
    }
    return max_profit;
    }
};