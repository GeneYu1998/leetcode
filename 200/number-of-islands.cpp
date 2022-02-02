#include <vector>
using namespace std;

template <class T>
class CSR_Matrix
{   
    public:
    vector<int> IntPtr;
    vector<int> ColIndex;
    vector<T> Value;
    int nnzs;  

    CSR_Matrix(){nnzs = 0;}  
    CSR_Matrix(vector<vector<T>>& grid, T empty_value)
    {   
        nnzs = 0;
        for(int i = 0; i < grid.size(); ++i)
        {   
            IntPtr.emplace_back(nnzs);
            for(int j = 0; j < grid[i].size(); ++j)
            {
               if(grid[i][j] != empty_value)
               {
                   nnzs++;
                   ColIndex.emplace_back(j);
                   Value.emplace_back(grid[i][j]);
               }
            }
        }
        IntPtr.emplace_back(nnzs);
    }
    
    void printCSR()
    {   
        cout << "--------------- Printing CSRMatrix ------------------------" << endl;
        cout << "IntPtr: ";
        for (int& Intptr:IntPtr) cout << Intptr << " ";
        cout << endl;
        cout << "ColIndex: ";
        for (int& col_id:ColIndex) cout << col_id << " ";
        cout << endl;
        cout << "Value: ";
        for (T& val:Value) cout << val << " ";
        cout << endl;
        cout << "Total Nonzeros: " << nnzs << endl;
    }

    ~CSR_Matrix(){;} //empty destructor  
};

// this binary searching assuming the input array is sorted by less<int>.
inline int binary_search(vector<int>& array, const int& lb, const int& ub, const int& target)
{     
      if(lb > ub) return -1;
      else
      {   
        int mid = (lb + ub) / 2;
        if(array[mid] > target) return binary_search(array, lb, mid - 1, target);
        else if(array[mid] < target) return binary_search(array, mid + 1, ub, target);
        else return mid;
       }
}

class Solution {
public:
    
    template<class T> 
    void connect_dfs(CSR_Matrix<T>* csr_grid, vector<bool>& vis, const int& row_id, const int& col_id)
    {   
        //cout << row_id << "-" << col_id << ": ";
        if(row_id == -1 || row_id == csr_grid->IntPtr.size() - 1 || col_id < 0) return; // out of boundary
        else
        {    
            //cout << row_id << "-" << col_id << ": ";
            int nnzs_id = binary_search(csr_grid->ColIndex, csr_grid->IntPtr[row_id], csr_grid->IntPtr[row_id + 1] - 1, col_id);
            if(nnzs_id != -1 && !vis[nnzs_id])
            {
               //cout << "id: " << nnzs_id << endl;          
               vis[nnzs_id] = true; //mark this element as visited.
               connect_dfs(csr_grid, vis, row_id - 1, col_id); //search up
               connect_dfs(csr_grid, vis, row_id, col_id - 1); //search left
               connect_dfs(csr_grid, vis, row_id, col_id + 1); //search right
               connect_dfs(csr_grid, vis, row_id + 1, col_id);//search down               
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
    CSR_Matrix<char>* csr_grid = new CSR_Matrix<char>(grid, '0');
    //csr_grid->printCSR(); // printing CSR_Matrix
    vector<bool> vis(csr_grid->nnzs, false); // a place_holder for visited elements.
    
    int IslandsCnt = 0;
    int curRow = 0;
    for(int i = 0; i < csr_grid->nnzs; ++i)
    {   
        while(curRow != csr_grid->IntPtr.size() - 1 && i == csr_grid->IntPtr[curRow + 1]) curRow++;
        if(!vis[i])
        {
           IslandsCnt++;
           connect_dfs(csr_grid, vis, curRow, csr_grid->ColIndex[i]);
        }
    }

    delete csr_grid; //destroy object
    return IslandsCnt;
    }
};