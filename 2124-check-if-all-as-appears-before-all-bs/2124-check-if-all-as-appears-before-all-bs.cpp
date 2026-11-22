class Solution {
public:
    bool checkString(string s) {
        bool f = true;
        for(auto &c : s) {
            if(c == 'b') f = false;
            if(!f && c == 'a') return false;
        }
        return true;
    }
};