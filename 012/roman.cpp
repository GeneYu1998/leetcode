#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
   
    string intToRoman(int num) {
    string out = {""};
    int digit, iter = 0;
    string ones = "IXCM";
    string fives = "VLD";
    string five, one, ten;
    while (num > 0)
    {   
        five = string(1, fives[iter]);
        one = string(1, ones[iter]);
        ten = string(1, ones[iter+1]);

        digit = num % 10;
        if (digit / 5 != 1)
        {
            if(digit == 4) out = one + five + out;
            else out = string(digit % 5, ones[iter]) + out;
        }
        else
        {
            if(digit == 9) out = one + ten + out;
            else out = five + string(digit % 5, ones[iter]) + out;            
        }
        
        num /= 10;
        iter++;
    }

    return out;
    }
};