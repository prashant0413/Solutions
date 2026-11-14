// APPROACH 1: USING DIKSTRA'S ALGORITHM
// TC: O(E LOG V)
// SC: O(V + E)
class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>> dist(V, {1e9, 0});
        dist[0].first = 0;
        dist[0].second = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int node = it.second;
            int d = it.first;
            
            for (auto adjNode: adj[node]) {
                int v = adjNode.first;
                int w = adjNode.second;
                
                if (w + d < dist[v].first) {
                    dist[v].first = w + d;
                    dist[v].second = dist[node].second;
                    pq.push({dist[v].first, v});
                } else if (w + d == dist[v].first) {
                    dist[v].second += dist[node].second;
                }
            }
        }
        
        return dist[V - 1].second;
    }
};
