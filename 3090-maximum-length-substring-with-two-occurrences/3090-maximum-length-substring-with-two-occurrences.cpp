class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int left = 0, right = 0;
        int ans = INT_MIN;
        while(right < n){
            freq[s[right] - 'a']++;

            while(freq[s[right] - 'a'] > 2){
                freq[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, right-left+1);
            right++;
        }
        return ans;
    }
};