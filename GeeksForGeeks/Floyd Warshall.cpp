// Approach 1
// TC = O(V^3)
// SC = O(V^2)
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int v = dist.size();
        for (int via = 0; via < v; via++) {
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    if (dist[i][via] == 1e8 || dist[via][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }
};
