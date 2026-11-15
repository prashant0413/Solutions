// APPROACH 1: USING DIJKSTRA ALGORITHM
// TC: O(E LOG V)
// SC: O(V)
class Solution {
  public:
    int findDelayTime(vector<vector<vector<int>>> &adj, int src) {
        int V = adj.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            
            for (auto it: adj[node]) {
                int v = it[0];
                int w = it[1];
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int mini = 0;
        for (int i = 0; i < V; i++) {
            if (i == src) continue;
            mini = max(dist[i], mini);
        }
        
        return mini == 1e9 ? -1 : mini;
    }
};
