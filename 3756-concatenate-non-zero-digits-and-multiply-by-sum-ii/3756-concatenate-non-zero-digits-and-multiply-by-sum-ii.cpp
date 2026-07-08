class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = s.length();
        vector<long long> prefS(n+1, 0);
        for(int i=0; i<n; i++){
            prefS[i+1] = prefS[i] + (s[i] - '0');
        }

        string temp = "";
        vector<int> cnt(n+1, 0);
        for(int i=0; i<n; i++){
            cnt[i+1] = cnt[i];
            if(s[i] != '0'){
                temp += s[i];
                cnt[i+1]++;
            }
        }

        int sz = temp.size();
        vector<long long> prefNum(sz+1, 0);
        vector<long long> powerN(sz+1, 1);

        for(int i=0; i<sz; i++){
            prefNum[i+1] = (prefNum[i] * 10 + (temp[i] - '0')) % mod;
            powerN[i+1] = (powerN[i] * 10) % mod;
        }

        for (auto& x : queries) {
            int l = x[0];
            int r = x[1];
            int left = cnt[l];
            int right = cnt[r+1];
            int len = right - left;

            long long sum = prefS[r+1] - prefS[l];

            long long num = (prefNum[right] - (prefNum[left] * powerN[len]) % mod + mod) % mod;
            
            ans.push_back(num * sum % mod);
        }
        return ans;
    }
};