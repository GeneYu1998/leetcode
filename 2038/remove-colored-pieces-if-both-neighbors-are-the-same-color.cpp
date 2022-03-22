#include "..\utils.cpp"

class Solution {
public:
    bool winnerOfGame(string colors) {
    int As = 0, Bs = 0, Alice_choices = 0, Bob_choices = 0;
    for(char& c: colors)
    {
       if(c == 'A')
       {   
           Bs = 0;
           if(++As > 2) ++Alice_choices;
       }
       else
       {   
           As = 0;
           if(++Bs > 2) ++Bob_choices;
       }
    }    
    return Alice_choices > Bob_choices;
    }
};