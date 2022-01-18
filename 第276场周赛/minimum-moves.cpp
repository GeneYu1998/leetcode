class Solution {
public:
    int minMoves(const int& target, const int& maxDoubles) {
    return (target!=1)?maxDoubles?(target & 1)?minMoves(target / 2, maxDoubles - 1) + 2:minMoves(target / 2, maxDoubles - 1) + 1:target - 1:0;
    }
};