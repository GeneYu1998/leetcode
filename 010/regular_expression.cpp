#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    char p_0 = p[0];
    if (p_0 == '.')
    {
        if (p.length()== 2)
        {
           if (p[1] == '*' && s.length() > 1)
           {
               return true;
           } 
           else return false;
        }
        else if (p.length()== 1 && s.length() == 1) return true;
        else return false;
    }
    else
    {
        if (p.length() == s.length() == 1 && p_0 == s[0]) return true;
        else if (p.length() > 1 && s.length() > 1)
        {   
            unordered_set<char> only_one;
            unordered_set<char> multi;         
            for(int i = 0; i < p.length(); ++i)
            {
               if(i != 0 && p[i] == '*')
               {
                  multi.insert(p[i-1]);
                //   only_one.erase(p[i-1]);
               } 
               else only_one.insert(p[i]);
            }
            
            unordered_set<char> s_set;

            for (const char s_11: s)
            {   
                if (s_set.find(s_11)!= s_set.end() && multi.find(s_11)== multi.end()) return false;            
                s_set.insert(s_11);
                if (only_one.find(s_11) == only_one.end()) return false;
            }
            return true;
        }
        else return false;
    }
    }
};