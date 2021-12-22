#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution{
    public:
    int output_time[6];
    int place_taken[6];
    bool valid = true;
    // sizeof(input) / sizeof(int)

    int bound_arr[6] = {3, 10, 6, 10, 6, 10};

    void find_max_time(int* input)
    {   
        sort(&input[0], &input[6], [&](int a, int b){return a>b;});
        // memcpy(output_time, input, sizeof(input));
        memset(output_time, 0, sizeof(output_time));
        memset(place_taken, 0, sizeof(place_taken));
        int place;
        for (int i = 0; i < 6; ++i)
        {   
            place = 0;
            int bound = this->bound_arr[i];
            while(place < 6)
            {
                // cout << place << endl;
                if (input[place] < bound && place_taken[place]!= 1)
                {   
                    output_time[i] = input[place];
                    place_taken[place] = 1;
                    // for (int i = 0; i < 6; ++i) cout << place_taken[i] << " ";
                    // cout << endl;
                    break;
                }
                ++place;
            } 
            if (place == 6) 
            {   
                this->valid = false;
                break;
            }
            if (i == 0 && output_time[0] == 2) this->bound_arr[1] = 4;

            // for (int i = 0; i < 6; ++i) cout << output_time[i] << " ";
            // cout << endl;
        }        

    } 
    
    void print_time()
    {    
         if (this->valid)
         {   
             printf("Max Time: %d%d:%d%d:%d%d\n", output_time[0], output_time[1], output_time[2],output_time[3],output_time[4],output_time[5]);
         }
         else
         {
             cout << "the input is invalid !!!" << endl;
         }
    }
};


int main()
{   
    int input[6];
    memset(input, -1, sizeof(input));
    printf("[Input format]:[0,1,2,3,4,5]\n\r");
    // scanf("[%d,%d,%d,%d,%d,%d]",&input[0],&input[1],&input[2],&input[3],&input[4],&input[5]);
    string line;
    int n = 0;
    getline(cin,line);
    stringstream ssin(line);
    while (ssin >> input[n]) n++;
    auto sol = Solution();
    sol.find_max_time(input);
    sol.print_time();
    return 0;
}