#include <iostream>
#include <string>

using namespace std;

class Solution {
public:

    void add_for_letter(int& out, string& s, int& index, int& index_bound)
    {   

        if (index >= index_bound) return;

        switch (s[index])
        {
            case('M'): 
            out += 1000;
            break;

            case('D'):  
            out += 500;
            break;

            case('C'):
            {   
                if (index < index_bound - 1)
                {
                  switch (s[index + 1])
                  {
                      case('D'):
                      {
                          out += 400;
                          index += 2;
                          add_for_letter(out, s, index, index_bound);
                          break;
                      }
                      case('M'):
                      {
                          out += 900;
                          index += 2;
                          add_for_letter(out, s, index, index_bound);
                          break;
                      }
                  }  
                }
              if (index < index_bound) out += 100;
              break;
            }


            case('L'): 
              out += 50;
              break;

            case('X'):
            {   
                if (index < index_bound - 1)
                {
                  switch (s[index + 1])
                  {
                      case('L'):
                      {
                          out += 40;
                          index += 2;
                          add_for_letter(out, s, index, index_bound);
                          break;
                      }
                      case('C'):
                      {
                          out += 90;
                          index += 2;
                          add_for_letter(out, s, index, index_bound);
                          break;
                      }
                  }  
                }
            if (index <index_bound) out += 10;
            break;
            }

            case('V'): 
              out += 5;
              break;

            case('I'):
            {   
                if (index < index_bound - 1)
                {
                  switch (s[index + 1])
                  {
                      case('V'):
                      {
                          out += 4;
                          index += 2;
                          add_for_letter(out, s, index, index_bound);
                          break;
                      }
                      case('X'):
                      {
                          out += 9;
                          index += 2;
                          add_for_letter(out, s, index, index_bound);
                          break;
                      }
                  }  
                }
                if (index <index_bound) out++;
                break;
            }
        } 
        ++index; 
        add_for_letter(out, s, index, index_bound);    
    }

    int romanToInt(string s) {
    int len = s.size();
    int out = 0, index = 0;
    add_for_letter(out, s, index, len);
    return out;
    }
};


int main()
{
    auto sol = Solution();
    string text = "VIII";
    // string text = "DCCC";
    int answer = sol.romanToInt(text);
    cout << endl << "Answer: " << answer; 

}