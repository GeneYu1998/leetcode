#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxStr;  
    int start=0;
    string lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return "";
        unordered_set<char> temp_str;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++)
        {   
            // delete elements inside temp_str until no elements before last s[i] exists.  
            while (temp_str.find(s[i]) != temp_str.end()){
                temp_str.erase(s[left]);
                left ++;
            }
            this->maxStr = max(maxStr,i-left+1);
            this->start = (this->maxStr==i-left+1)?left:this->start; 
            temp_str.insert(s[i]); // keep s[i] to be the right side.
        }
        return s.substr(this->start,this->maxStr);
        
    }
};

int main()
{
//// test case ////
string s = string{"pwwkewqwrr1aionzxnoiwqhjehhqwdeojajsdpqzxmlibcu1234567890"};
auto sol = Solution();
string longest_no_duplicate = sol.lengthOfLongestSubstring(s);
cout << "Answer: " << longest_no_duplicate << ", length: " << sol.maxStr << endl;
}