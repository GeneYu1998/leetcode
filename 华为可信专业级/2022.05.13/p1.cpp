/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: 上机编程认证
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 待实现函数，在此函数中填入答题代码
    int GetMaxQuantity(const vector<int> &productions, const vector<int> &plans, int window)
    {   
        int n = productions.size();
        int totalProd = 0;
        int lp = 0, rp = 0;
        
        for (int i = 0; i < n; ++i) {
            totalProd += !plans[i] ? 0 : productions[i];
        }
        
        for (; rp < window; ++rp) {
            if (!plans[rp]) {
                totalProd += productions[rp];
            }
        }
        
        int globalMax = totalProd;
        
        while(rp <= n) {
            totalProd += !plans[rp]?productions[rp] : 0; 
            totalProd -= !plans[lp]?productions[lp] : 0;
            globalMax = max(globalMax, totalProd);
            ++lp;
            ++rp;
        }
        
        return globalMax;
    }
};