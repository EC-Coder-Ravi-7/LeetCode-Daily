class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos, ans;
        for(auto &x:  nums){
            if(x < 0){
                neg.push_back(x);
            } else {
                pos.push_back(x);
            }
        }
        int n = neg.size(), m = pos.size();
        for(int i=0; i<n; i++){
            neg[i] = neg[i]*neg[i];
        }
        for(int i=0; i<m; i++){
            pos[i] = pos[i]*pos[i];
        }
        int i=0, j=n-1;
        while(i < m && j >=0){
            if(pos[i] < neg[j]){
                ans.push_back(pos[i]);
                i++;
            } else {
                ans.push_back(neg[j]);
                j--;
            }
        }
        while(j >= 0){
            ans.push_back(neg[j]);
            j--;
        }
        while(i < m){
            ans.push_back(pos[i]);
            i++;
        }
        return ans;
    }
};