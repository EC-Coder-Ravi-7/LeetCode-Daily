class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int l = 0;
        for(int l=0; l<n; l++){
            int count = 0;
            for(int r=l; r<n; r++){
                if(nums[r] == target){
                    count++;
                }
                int len = r - l +1;
                if(count > len/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};