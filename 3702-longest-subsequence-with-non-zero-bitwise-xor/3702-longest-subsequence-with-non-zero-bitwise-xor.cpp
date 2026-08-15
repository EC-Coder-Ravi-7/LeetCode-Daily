class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int Xor = nums[0];
        bool noon = false;
        for(int i=1; i<n; i++){
            Xor ^= nums[i];
            if(nums[i] > 0) noon = true;
        }
        if(Xor != 0) return n;
        return noon ? n-1 : 0;
    }
};