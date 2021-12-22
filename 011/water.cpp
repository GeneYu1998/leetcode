#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int AreaMax = 0;
    int maxArea(vector<int>& height) {
    int len = height.size();
    int left = 0, right = len - 1;
    while(left < right + 1)
    {   
        if (height[left] < height[right])
        {
        this->AreaMax = max(this->AreaMax, (right - left) * height[left]);
        ++left;
        }
        else
        {
        this->AreaMax = max(this->AreaMax, (right - left) * height[right]);    
        --right;
        }

    }
    return this->AreaMax;
    }
};