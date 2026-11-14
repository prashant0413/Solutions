// APPROACH 1: BRUTE FORCE
// TC: O(V^3)
// SC: O(V^2)
class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == 1e8 || dist[via][j] == 1e8) continue;
                    dist[i][j] = min(dist[i][via] + dist[via][j], dist[i][j]);
                }
            }
        }
    }
};
