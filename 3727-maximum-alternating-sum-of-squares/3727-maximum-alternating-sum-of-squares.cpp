class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++) {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end(), greater<int>());
        int mid = n / 2;
        long long sum1 = 0, sum2 = 0;
        if(n%2 == 0) {
            for(int i=0; i<mid; i++) {
                sum1 += pow(nums[i], 2);
            }
            for(int i=mid; i<n; i++) {
                sum2 += pow(nums[i], 2);
            }
        } else {
            for(int i=0; i<=mid; i++) {
                sum1 += pow(nums[i], 2);
            }
            for(int i=mid+1; i<n; i++) {
                sum2 += pow(nums[i], 2);
            }
        }
        return sum1 - sum2;
    }
};