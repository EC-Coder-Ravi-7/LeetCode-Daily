class Solution {
public:
    int minMoves2(vector<int>& nums) {
        auto mid = nums.begin() + nums.size() / 2;
        ranges::nth_element(nums, mid);
        int med = *mid, ans = 0;
        for(auto &x : nums) {
            ans += abs(x - med);
        }
        return ans;
    }
};