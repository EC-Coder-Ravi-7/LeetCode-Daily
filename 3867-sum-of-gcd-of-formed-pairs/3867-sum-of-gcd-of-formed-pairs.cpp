class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefGcd(n), prefMax(n);
        prefMax[0] = nums[0];
        for(int i=1; i<n; i++){
            prefMax[i] = max(prefMax[i-1], nums[i]);
        }
        for(int i=0; i<n; i++){
            prefGcd[i] = __gcd(prefMax[i], nums[i]);
        }
        sort(prefGcd.begin(), prefGcd.end());
        int i = 0, j = n-1;
        long long ans = 0;
        while(i < j){
            int mx = prefGcd[i];
            int mn = prefGcd[j];
            ans += __gcd(mx, mn);
            i++,j--;
        }
        return ans;
    }
};