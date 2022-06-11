#include "../utils.cpp"

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int pt = n, minFlip, accToOne = 0, curMin;

        while (--pt != 0) {
            if (s[pt] == '0') {
                ++accToOne;
            }
        }
        
        minFlip = accToOne;
        int accToZero = s[pt] == '1'? 1 : 0;

        while(++pt != n) {
            if (s[pt] == '0') {
                --accToOne;
            }
            minFlip = min(accToOne + accToZero, minFlip);
            if (s[pt] == '1') {
                ++accToZero;
            }
        }
        return minFlip;
    }
};