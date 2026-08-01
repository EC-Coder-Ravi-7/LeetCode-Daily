class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if (~n & 1) return true;

        vector dp(n, vector<int>(n, -1));
        auto maxD = [&](this auto&& maxD, int i, int j) -> int {
            int& res = dp[i][j];
            if (res != -1) return res;
            if (i == j) return res = nums[i];

            return res = max(nums[i] - maxD(i + 1, j),
                             nums[j] - maxD(i, j - 1));
        };

        return maxD(0, n - 1) >= 0;
    }
};