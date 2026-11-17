// APPROACH 1: DISJOINT SET TECHNIQUE
// TC: O(4.M.N)
// SC: O(M.N)
class DisjointSet {
public:
    vector<int> parent;
    vector<int> size;
    DisjointSet(int n) {
        size = vector<int>(n, 1);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int findUpar(int node) {
        return node == parent[node] ? node : parent[node] = findUpar(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        int up_u = findUpar(u);
        int up_v = findUpar(v);
        if (up_u == up_v) return;
        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            size[up_u] += size[up_v];
            parent[up_v] = up_u;
        }
    }
};

class Solution {
  public:
    int maxConnection(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0;
        DisjointSet ds(m * n);
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int no = i * n + j;
                for (int k = 0; k < 4;  k++) {
                    int nr = i + drow[k];
                    int nc = j + dcol[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int idx = nr * n + nc;
                        if (ds.findUpar(no) != ds.findUpar(idx)) {
                            ds.unionBySize(no, idx);
                        }
                    }
                }
                maxi = max(maxi, ds.size[ds.findUpar(no)]);
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                unordered_set<int> st;
                int size = 1;
                for (int k = 0; k < 4; k++) {
                    int nr = i + drow[k];
                    int nc = j + dcol[k];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        int up = ds.findUpar(nr * n + nc);
                        if (st.count(up)) continue;
                        st.insert(up);
                        size += ds.size[up];
                    }
                }
                maxi = max(maxi, size);
            }
        }
        
        return maxi;
    }
};
