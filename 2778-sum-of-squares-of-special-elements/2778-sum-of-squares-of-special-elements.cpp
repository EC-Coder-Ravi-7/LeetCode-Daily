class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> spe;
        for(int i=0; i<n; i++) {
            if(n % (i+1) == 0) {
                spe.push_back(nums[i]);
            }
        }
        int ans = 0;
        for(auto &x : spe) {
            ans += (x*x);
        }
        return ans;
    }
};