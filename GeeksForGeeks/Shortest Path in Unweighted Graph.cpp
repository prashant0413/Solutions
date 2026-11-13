// APPROACH 1
// TC: O(V + 2E)
// SC: O(V)
class Solution {
  public:
    int shortestPath(vector<vector<int>> &adj, int src, int dest) {
        int V = adj.size();
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        while (!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            
            for (auto it: adj[node]) {
                if (d + 1 < dist[it]) {
                    dist[it] = d + 1;
                    q.push({it, dist[it]});
                }
            }
        }
        
        return dist[dest] == 1e9 ? -1 : dist[dest];
    }
};
