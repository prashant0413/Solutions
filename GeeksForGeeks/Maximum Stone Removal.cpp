// APPROACH 1: DISJOINT SET TECHNIQUE
// TC: O(N)
// SC: O(N)
class DisjointSet {
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n) {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int findUpar(int node) {
        return node == parent[node] ? node : parent[node] = findUpar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int up_u = findUpar(u);
        int up_v = findUpar(v);
        if (up_u == up_v) return;
        if (size[up_v] < size[up_u]) {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        } else {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
    }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones) {
        int m = 0;
        int n = 0;
        for (auto it: stones) {
            m = max(m, it[0]);
            n = max(n, it[1]);
        }
        
        DisjointSet ds(m + n + 2);
        unordered_map<int, int> mpp;
        for (auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + m + 1;
            ds.unionBySize(nodeRow, nodeCol);
            mpp[nodeRow] = 1;
            mpp[nodeCol] = 1;
        }
        
        int cnt = 0;
        for (auto it: mpp) {
            if (ds.findUpar(it.first) == it.first) cnt++;
        }
        
        return stones.size() - cnt;
    }
};
