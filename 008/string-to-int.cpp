#include <string>
using std::string;

class Solution {
public:  
    bool exceed_int(const string& str, int& pt, long& res)
    {
        while(isdigit(str[pt]))
        {   
            res *= 10;
            res += str[pt] - '0';
            if (res > INT_MAX) return true;
            ++pt;
        }
        return false;         
    }

    int myAtoi(string str) {
    long res = 0;
    int len = str.size(), pt = 0;
    while(isspace(str[pt]) && pt != len - 1) pt++;
    if(pt == len) return res; // all char are spaces

    if(str[pt] == '-') return exceed_int(str, ++pt, res)?INT_MIN:(int)(0 - res);
    else if(str[pt] == '+') return exceed_int(str, ++pt, res)?INT_MAX:(int)(res);
    else if(isdigit(str[pt])) return exceed_int(str, pt, res)?INT_MAX:(int)(res);
    else return res;
    
    }
};