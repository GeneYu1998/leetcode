#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> ans;
    void recursive_search(string& valid, int left_cnt, int right_cnt)
    {
         if (left_cnt==0 && right_cnt==0)
         {
            ans.push_back(valid);
            return;
         }
         else
         {
            if (left_cnt > 0) 
            {   
                valid.push_back('(');
                recursive_search(valid, left_cnt - 1, right_cnt);
                valid.pop_back();
            }
            if (right_cnt > left_cnt) 
            {  
               valid.push_back(')');
               recursive_search(valid, left_cnt, right_cnt - 1); 
               valid.pop_back();
            }
         }
    }
    
    vector<string> generateParenthesis(int n) {
    string valid = string("(");
    int left_cnt = n - 1;
    int right_cnt = n;
    recursive_search(valid, left_cnt, right_cnt);
    return ans;
    }
};