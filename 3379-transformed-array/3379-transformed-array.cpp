class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            int x = nums[i];
            if(x > 0){
                ans[i] = nums[(i+x) % n];
            }
            if(x < 0){
                int idx = ((i+nums[i]) % n + n) % n;
                ans[i] = nums[idx];
            }
            if(x == 0){
                ans[i] = x;
            }
        }
        return ans;
    }
};