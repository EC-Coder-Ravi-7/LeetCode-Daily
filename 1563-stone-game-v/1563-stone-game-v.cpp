class Solution {
public:

    int t[501][501];

    int solve(int l, int r, vector<int>& currS){
        if(l >= r) return 0;
        if(t[l][r] != -1) return t[l][r];
        int ans = 0;

        for(int mid=l; mid<=r; mid++){
            int leftS = currS[mid] - (l-1 >= 0 ? currS[l-1] : 0);
            int rightS = currS[r] - currS[mid];

            if(leftS < rightS){
                ans = max(ans, leftS + solve(l, mid, currS));
            } else if(leftS > rightS){
                ans = max(ans, rightS + solve(mid+1, r, currS));
            } else {
                ans = max({ans, leftS + solve(l, mid, currS), rightS + solve(mid+1, r, currS)});
            }
        }
        return t[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> currS(n, 0);
        currS[0] = stoneValue[0];
        for(int i=1; i<n; i++){
            currS[i] = currS[i-1] + stoneValue[i];
        }
        memset(t, -1, sizeof(t));
        return solve(0, n-1, currS);
    }
};