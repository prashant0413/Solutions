// Approach 1
// TC = O(V + E)
// SC = O(1)
class DisJointSet {
    vector<int> size;
    vector<int> parent;
public:
    DisJointSet(int n) {
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int noOfCables = connections.size();
        if (noOfCables < n - 1) return -1;
        unordered_set<int> st;
        DisJointSet ds(n);
        for (auto it: connections) {
            ds.unionBySize(it[0], it[1]);
        }

        for (int i = 0; i < n; i++) {
            st.insert(ds.fp(i));
        }

        return st.size() - 1;
    }
};
