// Approach 1
// TC = O(m * n(LOG(m*n)))
// SC = O(m*n)
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        while(!pq.empty()) {
            int d = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && dist[nr][nc] > max(abs(heights[r][c] - heights[nr][nc]), d)) {
                    dist[nr][nc] =  max(abs(heights[r][c] - heights[nr][nc]), d);
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
