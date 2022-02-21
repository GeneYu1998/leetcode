#include "..\utils.cpp"

class Solution {
public:
    bool out_force;

    bool DominoSimulation(string& dominoes, const int& n)
    {   
        out_force = false;

        for(int i = 0; i < n; ++i)
        {
            if(dominoes[i] == 'R' && i != n - 1 && dominoes[i + 1] == '.') 
            {
                dominoes[i + 1] = '#';
            }
            else if(dominoes[i] == 'L' && i != 0)
            {
                if(dominoes[i - 1] == '.') 
                {   
                    out_force = true;
                    dominoes[i - 1] = 'L';
                }
                else if(dominoes[i - 1] == '#') 
                {
                    dominoes[i - 1] = '.';
                }
            }
        }

        for(int i = n - 1; i != 0; --i)
        {
           if(dominoes[i] == '#')
           {
               out_force = true;
               dominoes[i] = 'R';
           } 
        }
        
        return out_force;
    }

    string pushDominoes(string& dominoes) {
    while(DominoSimulation(dominoes, dominoes.size()));
    return dominoes;
    }
};