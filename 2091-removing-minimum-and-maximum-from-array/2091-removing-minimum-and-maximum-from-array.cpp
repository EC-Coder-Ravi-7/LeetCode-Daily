class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        for(int i=1; i<n; i++){
            if(nums[i] < nums[l]){
                l = i;
            }
            if(nums[i] > nums[r]){
                r = i;
            }
        }
        if(l < r){
            swap(l, r);
        }
        int ans = n;
        for(int i=0; i<=n; i++){
            int e = 0;
            if(r >= i){
                e = n - r;
            } else if(l >= i){
                e = n - l;
            }
            ans = min(ans, i + e);
        }
        return ans;
    }
};