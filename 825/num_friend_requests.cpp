#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
    int n = ages.size();
    sort(ages.begin(), ages.end(), [&](int a, int b){return a > b;});
    int y_pos;
    int x, y;
    int requests = 0, this_requests=0;
    for (int i = 0; i < n; ++i)
    {   
        x = ages[i];
        y_pos = i + 1;
        if (i!= 0 && x == ages[i - 1]) 
        {
            requests += this_requests;
        }
        else if (i != n - 1){
        this_requests = 0;
        while(y_pos != n)
        {   
            y = ages[y_pos];
            if (x < 100 && y > 100) ++y_pos;
            else
            {
            if (y <= 0.5 * x + 7) break;
            else
            {
               ++this_requests;
               ++y_pos;
            }
            }
        }
        requests += this_requests;
        }

    }
    return requests;
    }
};