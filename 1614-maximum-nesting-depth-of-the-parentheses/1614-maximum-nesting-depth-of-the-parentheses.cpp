class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, count = 0;
        for(auto &x : s){
            if(x == '('){
                count++;
            }
            if(x == ')'){
                ans = max(ans, count);
                count--;
            }
        }
        return ans;
    }
};