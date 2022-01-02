#include <string>
using namespace std;

class Solution {
public:
    // this function directly change the input string, instead of returning a copy.
    string replaceSpace(string& s) {
    if (s == "") return "";
    char* rep = "%20"; 
    int lp=s.size() - 1, rp = lp, rep_len = 3;

    //first sweep, record spaces.
    for(int i = 0; i < s.size(); ++i)
    {  
       if (isspace(s[i])) rp +=rep_len-1;
    }

    //alter string size
    s.resize(rp + 1);

    //backward assignment
    while(lp!=-1)
    {   
        if (isspace(s[lp])) 
        {   
            for (int i = rep_len-1; i!=-1; i--) 
            { 
                s[rp--] = rep[i];
            }
        }
        else 
        { 
            s[rp--] = s[lp];
        }
        --lp;
    }
    return s;
    }
};