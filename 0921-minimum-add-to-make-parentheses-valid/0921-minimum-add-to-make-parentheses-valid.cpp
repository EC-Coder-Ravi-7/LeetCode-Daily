class Solution {
public:
    int minAddToMakeValid(string s) {
        int b = 0, ans = 0;
        for(auto &x : s) {
            if(x == '(') {
                b++;
            } else {
                b--;
                if(b < 0) {
                    ans++;
                    b = 0;
                }
            }
        }
        return ans + b;
    }
};