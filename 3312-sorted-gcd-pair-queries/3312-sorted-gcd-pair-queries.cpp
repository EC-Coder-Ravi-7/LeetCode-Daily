class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int n = nums.size();
        vector<int> ans;
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx+1);
        vector<long long> exact(mx+1, 0);
        for(int x : nums){
            freq[x]++;
        }

        for(int g=mx; g>=1; g--){
            int count = 0;
            for(int m=g; m<=mx; m+=g){
                count += freq[m];
            }
            exact[g] = 1LL * count * (count-1)/2;
            
            for(int m=2*g; m<=mx; m+=g){
                exact[g] -= exact[m];
            }
        }

        vector<long long> pref;
        vector<int> values;
        long long sum = 0;
        for(int g=1; g<=mx; g++){
            if(exact[g] > 0){
                sum += exact[g];
                pref.push_back(sum);
                values.push_back(g);
            }
        }
        for(auto &x : queries){
            int idx = lower_bound(pref.begin(), pref.end(), x+1) - pref.begin();
            ans.push_back(values[idx]);
        }
        return ans;
    }
};