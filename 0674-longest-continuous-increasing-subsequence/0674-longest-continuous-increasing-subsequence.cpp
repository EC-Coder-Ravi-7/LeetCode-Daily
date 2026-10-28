class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1, ans = 1, n = nums.size();

        for(int i=1; i<n; i++) {
            if(nums[i-1] < nums[i]) {
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }
        }
        ans = max(ans, count);
        return ans;
    }
};