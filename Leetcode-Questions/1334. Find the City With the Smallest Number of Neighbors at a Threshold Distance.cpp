// Approach 1 using floyd warshall algorithm
// TC = O(n^3)
// SC = O(n^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == 1e9 || dist[via][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int min = INT_MAX;
        int node = -1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist[i][j] <= distanceThreshold) {
                    cnt += 1;
                }
            }
            if (cnt <= min) {
                if (cnt < min)
                    min = cnt;
                node = i;
            }
        }

        return node;
    }
};
