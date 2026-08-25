class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto &x : nums){
            mp[x]++;
        }
        int j = k;
        while(mp.find(j) != mp.end()){
            j += k;
        }
        return j;
    }
};