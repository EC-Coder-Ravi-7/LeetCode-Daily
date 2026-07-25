class Solution {
public:
    int maxProduct(int n) {
        string s = "";
        s += to_string(n);
        sort(s.begin(), s.end());
        int a = s[s.length()-1] - '0';
        int b = s[s.length()-2] - '0';
        return a * b;
    }
};