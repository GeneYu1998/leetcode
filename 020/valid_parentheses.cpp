#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    unordered_map<char, char> valid_set = {make_pair('(', ')'), make_pair('{', '}'), make_pair('[', ']')};
    vector<char> c_r;
    bool isValid(string s) {
         bool v = false;
         for (auto c:s)
         {
            if(valid_set.count(c)) c_r.push_back(valid_set[c]);
            else
            {
              if(c_r.empty()||c!=c_r.back()) return false;
              else c_r.pop_back();
            }
         }
         if(!c_r.empty()) return false;
         else return true;
    }
};