#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    string out = "";
    int size_s = strs.size();
    if (size_s <= 1) return strs[0];
    int pos = 0;
    char now;
    bool valid = true;
    while(true)
    {   
        now = strs[0][pos];
        for(int i=1; i < size_s; i++)
        {    
             if(pos == strs[i].length()) valid = false;
             else if(strs[i][pos]!=now) valid = false;
             if (!valid) break;
        }
        if (!valid) break;
        out += string(1, now);
        pos++;
    }

    return out;

    }
};