class Solution {
public:
    long long sum = 0;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int n, m;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        sum += grid[r][c];
        grid[r][c] = 0;

        for(int i=0; i<4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != 0) {
                dfs(nr, nc, grid);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] != 0) {
                    sum = 0;
                    dfs(i, j, grid);
                    if(sum%k == 0) ans++;
                }
            }
        }
        return ans;
    }
};