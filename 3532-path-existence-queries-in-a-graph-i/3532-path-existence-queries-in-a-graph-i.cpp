class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool unionSets(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j]) {
                parent[root_i] = root_j;
                size[root_j] += size[root_i];
            } else {
                parent[root_j] = root_i;
                size[root_i] += size[root_j];
            }
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DSU dsu(n);
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                dsu.unionSets(i, i - 1);
            }
        }
        
        vector<bool> answer;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            answer.push_back(dsu.find(u) == dsu.find(v));
        }
        
        return answer;
        
    }
};