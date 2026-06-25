class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        long long ans = 0;
        vector<int> pref(2*n+1, 0);

        pref[n] = 1;
        int count = n;
        long long prefS = 0;
        
        for(auto &x : nums){
            if(x == target){
                prefS += pref[count];
                count++;
                pref[count]++;
            } else{
                count--;
                prefS -= pref[count];
                pref[count]++;
            }
            ans += prefS;
        }
        return ans;
    }
};