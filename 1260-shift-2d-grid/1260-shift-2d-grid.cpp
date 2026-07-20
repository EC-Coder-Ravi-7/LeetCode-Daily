class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int total = m*n;
        k%=total;
        vector<vector<int>> ans(n, vector<int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int oldIdx = i*m+j;
                int newIdx = (oldIdx+k) % total;
                int newR = newIdx/m;
                int newC = newIdx%m;
                ans[newR][newC] = grid[i][j];
            }
        }
        return ans;
    }
};