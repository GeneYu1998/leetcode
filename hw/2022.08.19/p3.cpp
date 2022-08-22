/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: 上机编程认证
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */
#include <iostream>
#include <vector>
#include <array>
#include <type_traits>
#include <tuple>
#include <utility>
#include <algorithm>
#include <unordered_map>

using ULL = unsigned long long;
using namespace std;
static int letterCache[26];
static unordered_map<string, ULL> nameIndex;

class Solution {
public:
    // 待实现函数，在此函数中填入答题代码

    static void ClearLetterCache()
    {
        for (int i = 0; i < 26; ++i) {
            letterCache[i] = 0;
        }
    }

    static void GetLetterCache(const string &str)
    {
        int id;
        for (const char &c : str) {
            id = c - 'A';
            ++letterCache[id];
        }
    }

    static ULL Factorial(const int &n)
    {
        ULL fac = 1;
        for (int i = 2; i <= n; ++i) {
            fac *= i;
        }
        return fac;
    }

    static ULL GetPermutationsByLetterCache(const int &wordLen)
    {
        ULL permute = Factorial(wordLen);
        for (int i = 0; i < 26; ++i) {
            if (!letterCache[i]) {
                continue;
            }
            permute /= Factorial(letterCache[i]);
        }
        return permute;
    }

    static ULL GetBehindLettersPermAcc(const int &len, const char &c)
    {
        ULL out = 0;
        int begin_id = c - 'A';
        int temp;
        for (int i = begin_id + 1; i < 26; ++i) {
            if (!letterCache[i]) {
                continue;
            }
            --letterCache[i];
            out += GetPermutationsByLetterCache(len);
            ++letterCache[i];
        }
        --letterCache[begin_id];
        return out;
    }

    static ULL computeStrIndexNum(const string &str)
    {
        int wordLen = str.size();
        ULL strIndexNum = GetPermutationsByLetterCache(wordLen);
        for (const char &c : str) {
            --wordLen;
            strIndexNum -= GetBehindLettersPermAcc(wordLen, c);
        }
        return strIndexNum;
    }

    static inline bool scolarNameCmp(const string &a, const string &b)
    {
        ULL indA = nameIndex[a];
        ULL indB = nameIndex[b];
        return indA == indB ? a < b : indA < indB;
    }

    vector<string> SortNames(const vector<string> &names)
    {
        vector<string> out;
        nameIndex.clear();
        for (const string &name : names) {
            out.emplace_back(name);
            ClearLetterCache();
            GetLetterCache(name);
            nameIndex[name] = computeStrIndexNum(name);
        }
        sort(out.begin(), out.end(), scolarNameCmp);
        return out;
    }
};