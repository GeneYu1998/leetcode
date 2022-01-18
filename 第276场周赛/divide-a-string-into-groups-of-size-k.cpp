#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
    vector<string> ans;
    int n = s.size(), m = n;
    while(n >= k)
    {
      ans.push_back(s.substr(m - n, k));
      n -= k;
    }
    if(n)
    {
      ans.push_back(s.substr(m - n, n));
      ans.back() += string(k - n, fill);
    }
    return ans;
   }
};