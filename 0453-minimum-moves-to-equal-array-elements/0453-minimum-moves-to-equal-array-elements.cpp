class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minE = *min_element(nums.begin(), nums.end());
        int res = 0;
        for(auto &x : nums) {
            res += (x - minE);
        }
        return res;
    }
};