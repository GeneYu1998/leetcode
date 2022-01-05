class Solution {
public:
    int translateNum(int num) {
    int prev_digit = num % 10, digit; 
    int prev_cnt_2=1, prev_cnt_1=1, cnt;
    num /= 10;
    if (num == 0) return 1;
    while(num > 0)
    {   
        digit = num % 10;
        if (digit==1 || (digit==2 && prev_digit < 6)) cnt = prev_cnt_2 + prev_cnt_1;
        else cnt = prev_cnt_1;
        prev_digit = digit;
        prev_cnt_2 = prev_cnt_1;
        prev_cnt_1 = cnt;
        num /= 10;
    }
    return cnt;
    }
};