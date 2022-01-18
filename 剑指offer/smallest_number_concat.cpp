#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool concatenate_less(const int& _a, const int& _b){ 
    int a = _a, b = _b;
    int log_10_a = 10, log_10_b = 10;
    while((a = a/10)!=0) log_10_a *= 10;
    while((b = b/10)!=0) log_10_b *= 10;
    if (log_10_a == log_10_b) return _a < _b;
    else return (float)(_a)/(_b) < (float)(log_10_a - 1) / (log_10_b - 1);
    }

    string minNumber(vector<int>& nums) {
    string out("");
    sort(nums.begin(), nums.end(), concatenate_less);
    for(auto& num:nums) out += to_string(num);
    return out;
    }
};


//////////////////////////////////////////// model answer .../////////////////////////////////////////////////////////////
class Solution {
public:
    string minNumber(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        string ans;
        for (int& i : nums) ans += to_string(i);
        return ans;
    }
    
    //hand-written quicksort
    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int i = l, j = r;
        while (i < j) {
            while (cmp(nums[l], nums[j]) && i < j) --j;
            while (!cmp(nums[l], nums[i]) && i < j) ++i;
            swap(nums[i], nums[j]);
        }
        swap(nums[l], nums[i]);
        quickSort(nums, l, i - 1);
        quickSort(nums, i + 1, r);
    }
    
    inline bool cmp(const int& a, const int& b) {
        long d1 = 10, d2 = 10;
        while (d1 <= a) d1 *= 10;
        while (d2 <= b) d2 *= 10;
        return a * d2 + b <= b * d1 + a;
    }
};