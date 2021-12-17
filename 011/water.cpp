#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
    int Area = 0;
    int right;
    for (int i = 0; i < height.size(); ++i)
    {   
        right = i;
        while((min(height[i], height[right++]) * (right - i)) > (height.size() - i));

    }
    }
};