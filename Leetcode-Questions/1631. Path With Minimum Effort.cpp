// APPROACH 1: SHORTEST PATH ALGORITHM
// TC: O(4.M.N LOG M.N)
// SC: O(M.N)
class Solution {
    typedef pair<int, pair<int, int>> pp;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> effort(m, vector<int>(n, 1e9));
        int drow[] = {0, 1, 0, -1};
        int dcol[] = {1, 0, -1, 0};
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        effort[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int diff = it.first;

            if (row == m - 1 && col == n - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int newEffort = max(diff, abs(heights[row][col] - heights[nr][nc]));
                    if (newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};
