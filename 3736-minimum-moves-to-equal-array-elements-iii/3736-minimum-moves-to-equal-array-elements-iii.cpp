class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxE =  *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(auto &x : nums){
            ans += (maxE - x);
        }
        return ans;
    }
};