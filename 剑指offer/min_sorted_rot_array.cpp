#include <vector>
using std::vector;

class Solution {
public:
    int rot_min;
    void binary_search(vector<int>& numbers, int& lower, const int& upper)
    {    
         if (numbers[lower] == numbers[upper])
         {   
             rot_min = numbers[lower];
             while(lower!=upper) 
             {
                ++lower;
                if(numbers[lower]!=numbers[upper])
                {   
                    rot_min = (numbers[lower] < rot_min)?numbers[lower]:rot_min;
                }
             }
             return;
         }
         else
         {
            int mid = (lower + upper) / 2; 
            if(lower == upper - 1) rot_min = numbers[upper] > numbers[lower]?numbers[lower]:numbers[upper];
            else if(numbers[mid] > numbers[upper])
            {
            binary_search(numbers, mid, upper);
            }
            else
            {
            binary_search(numbers, lower, mid);
            }
         }
    }

    int minArray(vector<int>& numbers) {
    int n = numbers.size();
    if (n == 1) return numbers[0];
    int start = 0;
    binary_search(numbers, start, n-1);
    return rot_min;
    }
};