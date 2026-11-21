class Solution {
public:

    unordered_map<int, vector<int>> adj;
    vector<int> result;
    vector<int> last;

    void dfs(int curr, string &s, vector<int>& parent) {
        int c = s[curr] - 'a';
        int nearAncestor = last[c];
        last[c] = curr;
        for(int child : adj[curr]) {
            dfs(child, s, parent);
        }
        last[c] = nearAncestor;

        if(curr != 0) {
            int nearParent = parent[curr];
            if(nearAncestor != -1) {
                nearParent = nearAncestor;
            }
            parent[curr] = nearParent;
            result[nearParent] += result[curr];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        for(int i=1; i<n; i++) {
            int u = parent[i];
            int v = i;
            adj[u].push_back(v);
        }
        result.assign(n, 1);
        last.assign(26, -1);
        dfs(0, s, parent);
        return result;
    }
};