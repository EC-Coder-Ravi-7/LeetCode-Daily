class Solution {
public:
    inline static int suff[100];
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        suff[n-1] = nums.back();

        for(int i=n-2; i>=0; i--){
            suff[i] = min(suff[i+1], nums[i]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, nums[i]);
            if(ans - suff[i] <= k){
                return i;
            }
        }
        return -1;
    }
};