#include <cstdlib>
using namespace std;

class Solution {
public:
    int divide(long dividend, long divisor) {
    long out_add = 1, out = 0;
    int sign = 1;

    if(dividend < 0) 
    {
        dividend = 0 - dividend;
        sign = 1 - sign;
    }

    if(divisor < 0) 
    {
      divisor = 0 - divisor;
      sign = 1 - sign;
    }
    
    // search for the upper bound
    long div = divisor;
    while(div < dividend)
    {
        div <<= 1;
        out_add <<= 1;
    }
    
    // quickdivide (reverse of quickpow)
    while(dividend != 0)
    {   
        if(div > dividend) 
        {
           div >>= 1;
           out_add >>= 1;            
        }
        else 
        {   
            dividend -= div;
            out += out_add;              
        }
    }
    
    out = sign?out:0-out;
    return out <INT_MIN?INT_MIN:(out> INT_MAX?INT_MAX:out);
    }
};