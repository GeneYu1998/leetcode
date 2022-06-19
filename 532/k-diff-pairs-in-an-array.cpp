#include "..\utils.cpp"

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        cache.clear();
        int cnt = 0;
        for (int& num : nums) {
            if (cache.count(num - k) && cache[num - k] != num && cache[num - k] != signedExisted) {
                if (cache[num - k] == num - 2 * k) {
                    cache[num - k] = signedExisted;
                } else {
                    cache[num - k] = num;
                }

                if (cache.count(num) && cache[num] == num + k) {
                    cache[num] = signedExisted;
                } else {
                    cache[num] = num - k;
                }
                ++cnt;
            } 

            if (cache.count(num + k) && cache[num + k] != num && cache[num + k] != signedExisted) {
                if (cache[num + k] == num + 2 * k) {
                    cache[num + k] = signedExisted;
                } else {
                    cache[num + k] = num;
                }

                if (cache.count(num) && cache[num] == num - k) {
                    cache[num] = signedExisted;
                } else {
                    cache[num] = num + k;
                }
                ++cnt;
            } 
            
            if (!cache.count(num)) {
                cache[num] = unsignedExisted;
            }
        }
        return cnt;
    }

private:
    unordered_map<int, int> cache;
    const static int unsignedExisted = 1e7 + 1;
    const static int signedExisted = -1e7 - 1;
};