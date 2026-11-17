// APPROACH 1: USING DISJOINT SET TECHNIQUE
// TC: O(K)
// SC: O(M.N)
class DisjointSet {
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet (int n) {
        size.resize(n, 1);
        parent.resize(n);
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
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        DisjointSet ds(n * m);
        int cnt = 0;
        vector<int> ans;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (auto it: operators) {
            int row = it[0];
            int col = it[1];
            int idx = row * m + col;
            
            if (grid[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            
            grid[row][col] = 1;
            cnt++;
            
            for (int k = 0; k < 4; k++) {
                int nr = row + drow[k];
                int nc = col + dcol[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    int num = nr * m + nc;
                    if (ds.findUpar(num) != ds.findUpar(idx)) {
                        cnt--;
                        ds.unionBySize(num, idx);
                    }
                }
            } 
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
