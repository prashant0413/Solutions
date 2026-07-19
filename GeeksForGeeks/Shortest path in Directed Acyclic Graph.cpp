// Approach 1
// TC = O(V + E)
// SC = O(V)
class Solution {
private:
    void topo(int node, stack<int> &st, vector<bool> &vis, vector<pair<int, int>> adj[]) {
        vis[node] = true;
        for (auto it: adj[node]) {
            if (!vis[it.first]) {
                topo(it.first, st, vis, adj);
            }
        }
        st.push(node);
    }
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // creating adjancency list
        vector<pair<int, int>> adj[V];
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }
        
        // topo sort
        stack<int> st;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i])
                topo(i, st, vis, adj);
        }
        
        vector<int> dist(V, 1e9);

        // relaxing the distances
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            for (auto it: adj[node]) {
                int v = it.first;
                int d = it.second;
                
                if (dist[node] + d < dist[v]) {
                    dist[v] = dist[node] + d;
                }
            }
        }
        
        for (int i = 0; i < V; i++) dist[i] = dist[i] == 1e9 ? -1 : dist[i];
        return dist;
    }
};
