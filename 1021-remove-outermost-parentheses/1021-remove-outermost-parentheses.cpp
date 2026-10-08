class Solution {
public:
    string removeOuterParentheses(string s) {
        int d = 0;
        string ans = "";
        for(char c : s) {
            if(c == '('){
                if(d > 0) {
                    ans +=c;
                }
                d++;
            } else {
                d--;
                if(d > 0){
                    ans += c;
                }
            }
        }
        return ans;
    }
};