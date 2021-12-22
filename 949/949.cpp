#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    int bound_1[4] = {2, 6, 10, 10};
    int bound_2[4] = {3, 4, 6, 10};
    bool two_head = true;
    int place_taken[4];
    int out[4];
    int place;
    bool valid = true;
    
    void fill_max(int length, vector<int>& arr, int* bound_arr)
    {  
       for (int i = 0; i < 4; ++i)
       {   
        place = 0;
        while (place < 4)
        {
            if (arr[place] < bound_arr[i] && place_taken[place]!= 1)
            {   
                out[i] = arr[place];
                place_taken[place] = 1;
                break;
            }        
            ++place;
        }

        if (two_head && i==0 && out[0]!= 2) 
        {
            two_head = false;
            break;
        } 

        if (place == 4)
        {   
            if (two_head)
            {  
               two_head = false;
               break;
            } 
            else
            {
                this->valid = false;
                break;
            }
        }       
        }
    }

    string largestTimeFromDigits(vector<int>& arr) {
    memset(out, 0, sizeof(out));
    memset(place_taken, 0, sizeof(place_taken));
    sort(arr.begin(), arr.end(), [&](int a, int b){return a>b;});
    fill_max(4, arr, bound_2);

    if (!two_head) 
    {
        memset(place_taken, 0, sizeof(place_taken));
        fill_max(4, arr, bound_1);         
    }

    if (valid)
    {
    if (two_head || (out[1] < bound_1[2] && out[1] > out[2])) return to_string(out[0]) + to_string(out[1]) + ":" + to_string(out[2]) + to_string(out[3]);
    else 
    {   
        return to_string(out[0]) + to_string(out[2]) + ":" + to_string(out[1]) + to_string(out[3]);
    }
    }
    else return "";
    }
};