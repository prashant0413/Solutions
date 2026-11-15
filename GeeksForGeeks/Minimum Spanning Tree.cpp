// APPROACH 1: PRIM'S ALGORITHM
// TC: O(E LOG E)
// SC: O(E)
class Solution {
  public:
    int primMST(vector<vector<vector<int>>> &adj) {
        int V = adj.size();
        // {dist, {u, v}}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        vector<bool> vis(V, false);
        int cost = 0;
        int cnt = 0;
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int d = it.first;
            int node = it.second;
            if (vis[node]) continue;
            
            vis[node] = true;
            cost += d;
            
            for (auto it: adj[node]) {
                int v = it[0];
                int w = it[1];
                if (vis[v]) continue;
                pq.push({w, v});
            }
        }
        
        return cost;
    }
};
