class Solution {
public:
    bool checkDivisibility(int n) {
        int t = n;
        int dS = 0, dP = 1;
        while(t > 0){
            int d = t % 10;
            t /= 10;
            dS += d;
            dP *= d;
        }
        return n % (dS+dP) == 0;
    }
};