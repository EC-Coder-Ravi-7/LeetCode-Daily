class Solution {
public:

    bool isRotational(vector<int>&nums, vector<int>& sorted, int start, int k) {
       int j = 0;

        for(int x = 0; x < 2 * k; x++) {
            int original = nums[start + (x % k)];
            while(j > 0 && original != sorted[start + j]) {
                if(sorted[start + j - 1] == sorted[start])
                    j--;
                else
                    j = 0;
            }
            if(original == sorted[start + j]) {
                j++;
                if(j == k)
                    return true;
            }
        }
        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;
        for(int k=1; k<=n; k++) {
            if(n%k != 0) {
                continue;
            }
            bool flag = true;

            for(int i=0; i<n; i+=k) {
                if(!isRotational(nums, sorted, i, k)) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans += k;
            }
        }
        return ans;
    }
};