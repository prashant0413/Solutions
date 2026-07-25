// Approach 1 using disjoint set
// TC = O(V + E)
// SC = O(V)
class DisJointSet {
    vector<int> parent;
    vector<int> size;
public:
    DisJointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
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
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
  public:
    int countConnected(int V, vector<vector<int>>& edges) {
        DisJointSet ds(V);
        for (auto it: edges) {
            ds.unionBySize(it[0], it[1]);
        }
        
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (ds.fp(i) == i) cnt++;
        }
        
        return cnt;
    }
};
