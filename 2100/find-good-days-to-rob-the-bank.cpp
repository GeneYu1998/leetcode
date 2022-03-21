#include "../utils.cpp"

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    vector<int> ans;
    int n = security.size();
    if(!time)
    {
        for(int i = 0; i < n; ++i) ans.push_back(i);
        return ans;
    }
    int weak_descant = 0, weak_increase = 0;
    queue<bool> q;
    for(int i = 1; i < n; ++i)
    {
        if(security[i] > security[i - 1])
        {
            ++weak_increase;
            weak_descant = 0;
        }
        else if(security[i] < security[i - 1])
        {
            ++weak_descant;
            weak_increase = 0;            
        }
        else
        {
            ++weak_descant;
            ++weak_increase;
        }

        if(i <= n - time && weak_descant >= time) q.push(1);
        else q.push(0);

        if(i >= 2 * time && q.front() && weak_increase >= time) ans.emplace_back(i - time);
        if(q.size() > time) q.pop();
    }   
    return ans;
    }
};