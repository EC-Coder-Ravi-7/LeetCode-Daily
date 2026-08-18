class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int i=0; i<=nums.size()-k; i++){
            unordered_set<int> st;
            for(int j=i; j<i+k; j++){
                st.insert(nums[j]);
            }
            for(auto num : st){
                mp[num]++;
            }
        }
        int ans = -1;

        for(auto &x : mp){
            int num = x.first;
            int count = x.second;
            if(count == 1){
                ans = max(ans, num);
            }
        }
        return ans;
    }
};