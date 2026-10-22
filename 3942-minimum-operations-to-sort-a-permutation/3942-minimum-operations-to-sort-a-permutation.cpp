class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (n == 2) return nums[0] == 0 ? 0 : 1;

        int c = nums[0];
        bool asc = true, desc = true;
        for (int i = 0; i < n; i++) {
            if (nums[i] != (c + i) % n) asc = false;
            if (nums[i] != ((c - i) % n + n) % n) desc = false;
        }
        if (!asc && !desc) return -1;

        vector<int> dist(2 * n, -1);
        queue<int> q;
        int start = (asc ? 0 : n) + c;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int s = q.front(); q.pop();
            int d = s / n, v = s % n;
            if (s == 0) return dist[s];

            int left = d == 0 ? d * n + (v + 1) % n : d * n + (v - 1 + n) % n;
            int rev  = d == 0 ? n + (v - 1 + n) % n : (v + 1) % n;

            for (int nx : {left, rev}) {
                if (dist[nx] == -1) {
                    dist[nx] = dist[s] + 1;
                    q.push(nx);
                }
            }
        }
        return -1;
    }
};