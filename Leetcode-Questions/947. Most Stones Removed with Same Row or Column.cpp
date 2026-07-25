// Approach 1
// TC = O(N)
// SC = O(m + n)
class DisjointSet {
    vector<int> size;
    vector<int> parent;
public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int fp(int node) {
        if (node == parent[node]) return node;
        return parent[node] = fp(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = fp(u);
        int pv = fp(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            size[pv] += size[pu];
            parent[pu] = pv;
        } else {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = INT_MIN;
        int maxCol = INT_MIN;
        for (auto it: stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 2);
        unordered_map<int, int> mpp;
        for (auto it: stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionBySize(nodeRow, nodeCol);
            mpp[nodeRow] = 1;
            mpp[nodeCol] = 1;
        }

        int cnt = 0;
        for (auto i: mpp) {
            if (ds.fp(i.first) == i.first) cnt++;
        }

        return n - cnt;
    }
};
