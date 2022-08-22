/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: 上机编程认证
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 待实现函数，在此函数中填入答题代码
    int maxReduced = 0;
    int curCodeMax = 0;
    
    int GetMaxReduced(const vector<int>& codeStats)
    {
        for (const int& codeNum: codeStats) {
            curCodeMax = max(curCodeMax, codeNum);
            maxReduced = max(maxReduced, curCodeMax - codeNum);
        }
        return maxReduced;
    }
};