class Solution {
public:
    bool canAliceWin(int n) {
        int mis = 55 - n;
        return lround(sqrt(2*mis)) % 2 == 1;
    }
};