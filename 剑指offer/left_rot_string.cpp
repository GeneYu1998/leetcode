#include <string>
using std::string;
class Solution {
public:
    string reverseLeftWords(string s, int n) {
    int size = s.size();
    if (n == 0 || n >= size) return s;
    else
    {
        return s.substr(n, size - n) + s.substr(0, n);
    }
    }
};