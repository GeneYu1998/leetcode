#include "..\utils.cpp"

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!q.empty()) {
                q.push(arr[i]);
                arr[i] = q.front();
                q.pop();                
            }
            
            if (!arr[i] && i < n - 1) {
                q.push(arr[++i]);
                arr[i] = 0; 
            } 
        }
    }
};