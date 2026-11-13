// APPROACH 1: TOPOSORT
// TC: O(V + E)
// SC: O(V)
class Solution {
private:
    void toposort(int i, vector<pair<int, int>> adj[], vector<bool> &vis, stack<int> &st) {
        vis[i] = true;
        
        for (auto it: adj[i]) {
            if (!vis[it.first]) toposort(it.first, adj, vis, st);
        }
        
        st.push(i);
    }
public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[V];
        for (auto edge: edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        
        stack<int> st;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                toposort(i, adj, vis, st);
            }
        }
        
        vector<int> dist(V, -1);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (dist[node] == -1) continue;
            
            for (auto it: adj[node]) {
                int adjNode = it.first;
                int edgeWeight = it.second;
                if ((dist[adjNode] == -1 )|| (dist[node] + edgeWeight < dist[adjNode])) {
                    dist[adjNode] = dist[node] + edgeWeight;
                }
            }
        }
        
        return dist;
    }
};
