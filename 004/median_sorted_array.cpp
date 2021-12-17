#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:

    double findMedianSortedArrays_pointer(vector<int>* nums1, vector<int>* nums2, int& m, int& n) 
    {  
       if(m>1 || n>1)
       {

       }
       bool odd = ((m + n) % 2 == 1)?true:false;
       if (m < n)
       {
           auto temp = nums1;
           nums1 = nums2;
           nums2 = temp;
           auto temp_n = m;
           m = n;
           n = temp_n;
       }
       int mid_m = m / 2;
       int mid_n = n / 2;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size();
        int n = nums2.size(); 
        findMedianSortedArrays_pointer(&nums1, &nums2, m, n);
    }

};



int main()
{
    auto nums1 = vector<int>{1, 3, 7, 11, 29, 57};
    auto nums2 = vector<int>{3, 4, 10, 17, 19, 21, 27, 30, 31, 33};
    
    cout << 'Median: ' << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}
