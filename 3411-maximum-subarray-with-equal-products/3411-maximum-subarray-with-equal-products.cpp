class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 2, left = 0, prod = 1;
        for(int r=0; r<nums.size(); r++) {
            int x = nums[r];
            while(gcd(prod, x) > 1) {
                prod /= nums[left++];
            }
            prod *= x;
            ans = max(ans, r-left+1);
        }
        return ans;
    }
};