class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st1, st2;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                st1.insert(nums[i] ^ nums[j]);
            }
        }
        for(auto &a : st1){
            for(auto &b : nums){
                st2.insert(a ^ b);
            }
        }
        return st2.size();
    }
};