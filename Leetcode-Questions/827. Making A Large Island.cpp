// Approach 1
// TC = O(N*N)
// SC = O(N)
class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUpar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int up = findUpar(u);
        int vp = findUpar(v);
        if (up == vp) return;
        if (size[up] < size[vp]) {
            size[vp] += size[up];
            parent[up] = vp;
        } else {
            size[up] += size[vp];
            parent[vp] = up;
        }
    }
};

class Solution {
    bool isValid(int nr, int nc, int n) {
        return nr >= 0 && nr < n && nc >= 0 && nc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, 1, 0, -1};
                for (int idx = 0; idx < 4; idx++) {
                    int nr = i + drow[idx];
                    int nc = j + dcol[idx];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int nodeNo = i * n + j;
                        int adjNo = nr * n + nc;
                        ds.unionBySize(nodeNo, adjNo);
                    }
                }
            }
        }
        
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, 1, 0, -1};
                set<int> comp;
                for (int idx = 0; idx < 4; idx++) {
                    int nr = i + drow[idx];
                    int nc = j + dcol[idx];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        comp.insert(ds.findUpar(nr * n + nc));
                    }
                }
                int sizeTotal = 0;
                for (auto it: comp) {
                    sizeTotal += ds.size[it];
                }
                maxi = max(sizeTotal + 1, maxi);
            }
        }

        for (int node = 0; node < n * n; node++) {
            maxi = max(maxi, ds.size[ds.findUpar(node)]);
        }
        return maxi;
    }
};
