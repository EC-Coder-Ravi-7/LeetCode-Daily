class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefS(n+1, 0);
        for(int i=0; i<n; i++) {
            prefS[i+1] = prefS[i] + nums[i];
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            for(int j=i+l; j<= min(i+r, n); j++) {
                int sum = prefS[j] - prefS[i];
                if(sum > 0) {
                    ans = min(ans, sum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};