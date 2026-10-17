class Solution {
public:

    int getDigitSUm(int num) {
        int sum = 0;
        while(num > 0) {
            int digit = num % 10;
            num /= 10;
            sum += digit;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> afterSort(nums);

        auto lambda = [&](int num1, int num2) {
            int sum1 = getDigitSUm(num1);
            int sum2 = getDigitSUm(num2);
            if(sum1 != sum2) return sum1 < sum2;

            return num1 < num2;
        };

        sort(afterSort.begin(), afterSort.end(), lambda);
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]] = i;
        }
        int count = 0;

        for(int i=0; i<n; i++) {
            int expect = afterSort[i];
            int currV = nums[i];
            if(expect == currV) continue;
            int idx = mp[expect];
            nums[i] = expect;
            nums[idx] = currV;

            mp[expect] = i;
            mp[currV] = idx;
            count++;
        }

        return count;
    }
};