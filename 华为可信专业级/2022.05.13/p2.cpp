/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: 上机编程认证
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    static inline bool sortAbilities (const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) == get<2>(b) ? (get<1>(a) == get<1>(b) ? get<0>(a) < get<0>(b) : get<1>(a) > get<1>(b)) : get<2>(a) > get<2>(b);
    }
    
    // 待实现函数，在此函数中填入答题代码
    vector<vector<int>> GetRecruitmentResult(const vector<array<int, 3>>& deptDemands,
        const vector<array<int, 2>>& candidateAbilities) {   
        int n = candidateAbilities.size();
        int nDep = deptDemands.size();
        vector<vector<int>> result(nDep, vector<int>());
        
        vector<tuple<int, int, int>> candidates;
        vector<tuple<int, int, int>> candidates_origin;
        for (int i = 0; i < n; ++i) {
            candidates.emplace_back(make_tuple(i, candidateAbilities[i][0], candidateAbilities[i][1]));
            candidates_origin.emplace_back(make_tuple(i, candidateAbilities[i][0], candidateAbilities[i][1]));
        }
        
        sort(candidates.begin(), candidates.end(), sortAbilities);
        
        // 常规阶段
        vector<bool> normalRecruit(nDep, true);
        vector<int> alreadyRecruit(nDep, 0);
        bool flag = true;
        vector<bool> match(nDep, true);
        while (flag) {
           flag = false;
           auto iter = candidates.begin();
           for (int i = 0 ; i < nDep; ++i) {
               flag |= (normalRecruit[i] && match[i]);
               if (!normalRecruit[i] || !match[i]) continue;
               match[i] = false;
               for (auto iter = candidates.begin(); iter != candidates.end();) {
               if(!normalRecruit[i]) break;
               tuple<int, int, int> cand = *iter;
               if (alreadyRecruit[i] < deptDemands[i][0] && get<2>(cand) >= deptDemands[i][2] && get<1>(cand) >= deptDemands[i][1]) {
                   result[i].emplace_back(get<0>(cand));
                   iter = candidates.erase(iter);
                   ++alreadyRecruit[i];
                   match[i] = true;
                   if (alreadyRecruit[i] == deptDemands[i][0]) normalRecruit[i] = false;
                   break;
               } else {
                   ++iter;
               }
               }
           } 
        }
        
        // 补录取
        vector<bool> Recruit(nDep, true);
        flag = true;
        for (int i = 0 ; i < nDep; ++i) {
        if(!result[i].size()) continue;
        tuple<int, int, int> lastOne = candidates_origin[result[i].back()];
            
        for (auto canddd = candidates.begin(); canddd != candidates.end();) {
            if (!Recruit[i]) break;
            if (get<1>(*canddd) >= get<1>(lastOne) && get<2>(*canddd) >= get<2>(lastOne)) {
                result[i].emplace_back(get<0>(*canddd));
                Recruit[i] = false;
                if (get<1>(*canddd) == get<1>(lastOne) && get<2>(*canddd) == get<2>(lastOne)) {
                    flag = false;    
                }
                canddd = candidates.erase(canddd);
            }
            else {
                ++canddd;
            }
        } 
        }              
        return result;
    }
};