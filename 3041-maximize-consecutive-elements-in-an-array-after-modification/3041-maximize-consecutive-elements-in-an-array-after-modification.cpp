class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mp;
        int ans = 0;
        for(auto &x : nums){
            mp[x+1] = mp[x] + 1;
            mp[x] = mp[x-1] + 1;
            ans = max({ans, mp[x], mp[x+1]});
        }
        return ans;
    }
};