class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;
        for(auto &x : arr1) {
            bool flag = true;
            for(auto &x1 : arr2) {
                if(abs(x-x1) <= d) {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};