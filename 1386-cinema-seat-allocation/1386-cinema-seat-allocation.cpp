class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9)
                rows[row] |= 1 << col;
        }

        int ans = 2 * (n - rows.size());

        int left = 0;
        int middle = 0;
        int right = 0;

        for (int col = 2; col <= 5; ++col)
            left |= 1 << col;

        for (int col = 4; col <= 7; ++col)
            middle |= 1 << col;

        for (int col = 6; col <= 9; ++col)
            right |= 1 << col;

        for (auto& [row, mask] : rows) {
            bool l = (mask & left) == 0;
            bool m = (mask & middle) == 0;
            bool r = (mask & right) == 0;

            if (l && r)
                ans += 2;
            else if (l || m || r)
                ans += 1;
        }

        return ans;
    }
};