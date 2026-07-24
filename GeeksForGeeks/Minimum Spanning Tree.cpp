// Approach 1
// TC = O(E*LOG(E))
// SC = O(E)
class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Prim's Algorithm
        vector<pair<int, int>> adj[V];
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        int totalCost = 0;
        vector<bool> visited(V, false);
        
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if (visited[node]) continue;
            
            visited[node] = true;
            totalCost += wt;
            
            for (auto i: adj[node]) {
                int v = i.first;
                int w = i.second;
                if (!visited[v]) {
                    pq.push({w, v});
                }
            }
        }
        return totalCost;
    }
};
