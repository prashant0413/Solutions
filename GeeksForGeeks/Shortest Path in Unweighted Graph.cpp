// Approach 1
// TC = O(V + 2E)
// SC = O(V)
class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        int dis[V];
        for (int i = 0 ; i < V; i++)
            dis[i] = INT_MAX;
            
        vector<int> adj[V];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        q.push(src);
        dis[src] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int i: adj[node]) {
                if (dis[node] + 1 < dis[i]) {
                    dis[i] = dis[node] + 1;
                    q.push(i);
                }
            }
        }
        
        return dis[dest] == INT_MAX ? -1 : dis[dest];
    }
};
