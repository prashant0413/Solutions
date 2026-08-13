// Approach 1
// TC = O(V + 2E)
// SC = O(V)
class Solution {
    int timer = 1;
private:
    void dfs(int node, int parent, int tin[], int low[], vector<vector<int>> &bridges, vector<int> adj[], vector<bool> &vis) {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it: adj[node]) {
            if (it == parent) continue;
            if (vis[it]) {
                low[node] = min(low[node], low[it]);
            } else {
                dfs(it, node, tin, low, bridges, adj, vis);
                low[node] = min(low[node], low[it]);
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // creating adjencency list
        vector<int> adj[n];
        for (auto i: connections) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, tin, low, bridges, adj, vis);
        return bridges;
    }
};
