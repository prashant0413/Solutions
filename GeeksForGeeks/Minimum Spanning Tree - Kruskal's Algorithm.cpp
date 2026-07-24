// Approach 1
// TC = O(E*LOG(E))
// SC = O(V)
class DisjointSet {
    vector<int> size;
    vector<int> parent;
public:
    DisjointSet(int n) {
        size = vector<int>(n, 1);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    void unionBySize(int u, int v) {
        int up_u = findUpar(u);
        int up_v = findUpar(v);
        if (up_u == up_v) return;
        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
    
    int findUpar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
};

class Solution {
  public:
    struct cmp {
        bool operator()(vector<int> &a, vector<int> &b) {
            if (a[2] != b[2])
                return a[2] < b[2];
            return a[0] < b[0];
        }
    };
  
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        sort(begin(edges), end(edges), cmp());
        DisjointSet ds(V);
        int totalCost = 0;
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (ds.findUpar(u) == ds.findUpar(v)) continue;
            totalCost += w;
            ds.unionBySize(u, v);
        }
        return totalCost;
    }
};
