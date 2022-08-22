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
#include <unordered_set>

using namespace std;

class Solution {
public:
    // 待实现函数，在此函数中填入答题代码
    // threadOps的每个元素（threadOps[i]）为一个线程的指令序列
    // threadOps[i]的每个元素（threadOps[i][j]）为一个指令，如：
    // 指令为 read(para)，则 threadOps[i][j].first = "read", threadOps[i][j].second = "para"；write 命令类似
    // 指令为 lock，则 threadOps[i][j].first = "lock", threadOps[i][j].second 值无效；unlock 命令类似
    unordered_set<string> compete_data;
    unordered_map<string, vector<int>> data_read_without_lock;
    unordered_map<string, vector<int>> data_write_without_lock;

    bool g_lock { false };

    void unordered_map_insert(const int &id, unordered_map<string, vector<int>> &map, string &value)
    {
        if (map.count(value)) {
            map[value].emplace_back(id);
        } else {
            map[value] = vector<int> { id };
        }
    }

    void map_check_value_other_thread(const int &id, unordered_map<string, vector<int>> &map_for_check, string &value)
    {
        if (map_for_check.count(value)) {
            auto &ids = map_for_check[value];
            for (int &value_id : ids) {
                if (value_id != id) {
                    compete_data.insert(value);
                    return;
                }
            }
        }
    }

    void ParseKeyInsert(const int &id, string &key, string &value)
    {
        if (key == "lock") {
            g_lock = true;
            return;
        }

        if (key == "unlock") {
            g_lock = false;
            return;
        }

        if (key == "read" && !g_lock) {
            unordered_map_insert(id, data_read_without_lock, value);
            return;
        }

        if (key == "write" && !g_lock) {
            unordered_map_insert(id, data_write_without_lock, value);
        }
    }

    void ParseKeyCheck(const int &id, string &key, string &value)
    {
        if (compete_data.count(value)) {
            return;
        }

        if (key == "lock") {
            g_lock = true;
            return;
        }

        if (key == "unlock") {
            g_lock = false;
            return;
        }

        if (key == "read" || key == "write") {
            map_check_value_other_thread(id, data_write_without_lock, value);
        }

        if (key == "write" && g_lock) {
            map_check_value_other_thread(id, data_read_without_lock, value);
        }
    }

    void ProcessThreadOp(const int &id, const vector<pair<string, string>> &threadOp, bool first_time)
    {
        for (const auto &cmd : threadOp) {
            string key = cmd.first;
            string value = cmd.second;
            if (first_time) {
                ParseKeyInsert(id, key, value);
            } else {
                ParseKeyCheck(id, key, value);
            }
        }
    }

    void reorder_vector(vector<string> &vec)
    {
        for (auto it = compete_data.begin(); it != compete_data.end(); ++it) {
            vec.emplace_back(*it);
        }
        sort(vec.begin(), vec.end());
    }

    vector<string> GetDataRaces(const vector<vector<pair<string, string>>> &threadOps)
    {
        vector<string> result;
        int thread_num = threadOps.size();

        for (int i = 0; i < thread_num; ++i) {
            ProcessThreadOp(i, threadOps[i], true);
        }
        for (int i = 0; i < thread_num; ++i) {
            ProcessThreadOp(i, threadOps[i], false);
        }

        reorder_vector(result);
        return result;
    }
};