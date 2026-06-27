class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;
        for (auto& x : nums) {
            mp[x]++;
        }
        int ans = 0;
        if (mp.count(1)) {
            int ones = mp[1];

            if (ones % 2 == 0)
                ans = max(ans, ones - 1);
            else
                ans = max(ans, ones);
        }
        for (auto& x : mp) {
            long long curr = x.first;
            int len = 0;

            if (curr != 1) {
                while (mp.count(curr) && mp[curr] > 1) {
                    len += 2;
                    if(curr > 1e9) break;
                    curr *= curr;
                }
            }
            if (mp.count(curr)) {
                len += 1;
            }else {
                len--;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};