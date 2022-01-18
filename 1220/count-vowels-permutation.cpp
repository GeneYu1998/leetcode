#include <vector>
using std::vector;
using uLL = unsigned long long;


class Solution {
public:
    unsigned int cnt;
    static const uLL mod_num = (const uLL)(1000000007);
    
    int countVowelPermutation(int n) {
    cnt = 0;
    vector<vector<uLL>> multi = {{0, 1, 1, 0, 1}, {1, 0, 1, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 1, 0}};
    int problem_size = 5;
    vector<uLL> res(problem_size, 1);
    // quick_pow for matrix;
    matrix_quick_pow(multi, res, n - 1, problem_size);
    // collecting results
    for(auto &ans: res) cnt += ans % (mod_num);
    return cnt % (mod_num);
    }

    void matrix_quick_pow(vector<vector<uLL>>& mat, vector<uLL>& res, const int& n, const int& size)
    {   
        if(!n) return;

        if(n & 1) res = matrix_vector_multi(mat, res, size);

        mat = matrix_multi(mat, mat, size);
        matrix_quick_pow(mat, res, n >> 1, size);
    }

    vector<uLL> matrix_vector_multi(vector<vector<uLL>>& mat, vector<uLL>& vec, const int& size)
    {   
        vector<uLL> out(size, 0);
        for(int i = 0; i < size; ++i)
        {
           for(int k = 0; k < size; ++k)
           {    
                out[i] += (mat[i][k] * vec[k]) % (mod_num);
           }
        }     
        return out;   
    }

    vector<vector<uLL>> matrix_multi(vector<vector<uLL>>& mat1, vector<vector<uLL>>& mat2, const int& size)
    {    
        vector<vector<uLL>> out(size, vector<uLL>(size, 0));
        uLL tmp;
        for(int i = 0; i < size; ++i)
        {
           for(int k = 0; k < size; ++k)
           {   
               tmp = mat1[i][k];
               for (int j = 0; j < size; ++j)
               {   
                   out[i][j] += (tmp * mat2[k][j]) % (mod_num);
               }
           }
        }
        return out;
    }
};
