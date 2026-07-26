// Approach 1
// TC = O(K)
// SC = O(m*n)
class DisjointSet {
    vector<int> size;
    vector<int> parent;
public:
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
        int up_u = findUpar(u);
        int up_v = findUpar(v);
        if (up_u == up_v) return;
        if (size[up_u] < size[up_v]) {
            size[up_v] += size[up_u];
            parent[up_u] = up_v;
        } else {
            size[up_u] += size[up_v];
            parent[up_v] = up_u;
        }
    }
};

class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        vector<int> ans;
        int cnt = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (auto it: operators) {
            int row = it[0];
            int col = it[1];
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            for (int i = 0; i < 4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 1) {
                    int nodeNo = row * m + col;
                    int adjNo = nr * m + nc;
                    if (ds.findUpar(nodeNo) != ds.findUpar(adjNo)) {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNo);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
