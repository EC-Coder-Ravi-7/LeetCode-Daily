class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> ar = arr, ans;
        unordered_map<int, int> mp;
        sort(ar.begin(), ar.end());
        int rank = 1;
        for(int i=0; i<n; i++){
            if(mp.find(ar[i]) == mp.end()){
                mp[ar[i]] = rank;
                rank++;
            }
        }
        for(int i=0; i<n; i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};