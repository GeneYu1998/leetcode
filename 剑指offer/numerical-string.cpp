#include <string>
using std::string;

class Solution {
public:
    bool isInteger(const string& s, int& pos, const int start_pos, const int& end_pos)
    {   
        if(pos == end_pos && isdigit(s[pos])) return true;
        else if(isdigit(s[pos])) return isInteger(s, ++pos, start_pos, end_pos);
        else if(pos == start_pos && pos != end_pos && (s[pos] == '-' || s[pos] == '+')) return isInteger(s, ++pos, start_pos, end_pos);
        else return false;
    }

    bool isDecimal(const string& s, int& pos, const int start_pos, const int& end_pos)
    {
        if(s[pos] == '.')
        {   
            if(pos == end_pos && pos != 0 && isdigit(s[pos - 1])) return true;
            else return isdigit(s[++pos]) && (isInteger(s, pos, start_pos + 1, end_pos) || isScientific(s, pos, pos, end_pos));
        }
        else return false;
    }

    bool isScientific(const string& s, int& pos, const int start_pos, const int& end_pos)
    {
        if((s[pos] == 'e' || s[pos] == 'E') && pos != end_pos && pos != 0 && (isdigit(s[pos - 1]) || (s[pos - 1] == '.' && pos != 1 && isdigit(s[pos - 2])))) return isInteger(s, ++pos, start_pos + 1, end_pos);
        else return false;
    }

    bool isNumber(string s) {
    if(s.size() == 0) return false;
    int lp = 0, rp = s.size() - 1;
    while(isspace(s[rp]) && rp != 0) rp--; // trim back space
    if(rp == lp && isspace(s[rp])) return false;
    while(isspace(s[lp])) lp++; // trim front space
    return isInteger(s, lp, lp, rp) || isDecimal(s, lp, lp, rp) || isScientific(s, lp, lp, rp);
    }
};