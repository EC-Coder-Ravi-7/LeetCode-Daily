class Solution {
public:
    int minimumPushes(string word) {
        vector<int> mp(26, 0);
        int assign = 2;
        for(auto &c : word){
            mp[c - 'a']++;
        }
        sort(mp.rbegin(), mp.rend());
        vector<int> freq(26, 0);
        int ans = 0;
        for(int i=0; i<26; i++){
            freq[i] = mp[i];
            int press = (i/8 + 1);
            ans += (freq[i] * press);
        }
        return ans;
    }
};