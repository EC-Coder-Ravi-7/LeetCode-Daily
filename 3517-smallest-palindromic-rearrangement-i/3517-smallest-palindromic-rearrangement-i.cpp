class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        string temp = "";
        for(int i=0; i<n/2; i++){
            temp += s[i];
        }
        sort(temp.begin(), temp.end());
        string ans = temp;
        if(n%2 != 0){
            ans += s[n/2];
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};