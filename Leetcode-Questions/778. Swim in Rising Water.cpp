// Approach 1 using Binary Search on answers
// TC = O(n^2 * log(n))
// SC = O(n^2)
class Solution {
    int n;
public:
    bool isPossible(vector<vector<int>>& grid, int i, int j, int t, vector<vector<bool>> &vis, int drow[], int dcol[]) {
        if (i == n - 1 && j == n - 1) return true;
        vis[i][j] = true;
        for (int k = 0; k < 4; k++) {
            int nr = i + drow[k];
            int nc = j + dcol[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] <= t) {
                if (isPossible(grid, nr, nc, t, vis, drow, dcol)) return true;
            }
        }
        return false;
    } 

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int l = grid[0][0];
        int r = n*n - 1;
        int result = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (l <= r) {
            int mid = l + (r - l) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (isPossible(grid, 0, 0, mid, vis, drow, dcol)) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }
};

// Approach 2 using Shortest path
// TC = O(n^2 * log(n))
// SC = O(n^2)
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == n -1 && c == n -1) return t;
            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = true;
                    pq.push({max(t, grid[nr][nc]), {nr, nc}});
                }
            }
        } 
        return 0;
    }
};
