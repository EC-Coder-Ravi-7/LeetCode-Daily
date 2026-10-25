class Solution {
public:

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int n, m, ans = 0;
    bool flag = true;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        grid[r][c] = 1;
        if(r == 0 || r == n-1 || c == 0 || c == m-1) {
            flag = false;
        }
        for(int i=0; i<4; i++) {
            int newR = r + dr[i];
            int newC = c + dc[i];
            if(newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 0) {
                dfs(newR, newC, grid);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    flag = true;
                    dfs(i, j, grid);
                    if(flag) ans++;
                }
            }
        }
        return ans;
    }
};