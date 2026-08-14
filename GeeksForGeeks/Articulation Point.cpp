// Approach 1
// TC = O(V + 2E)
// SC = O(V)
class Solution {
    int timer = 0;
private:
    void dfs(int node, int parent, int tin[], int low[], vector<int> adj[], vector<bool> &vis, vector<int> &mark) {
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (int it: adj[node]) {
            if (it == parent) continue;
            if (vis[it]) {
                low[node] = min(low[node], tin[it]);
            } else {
                dfs(it, node, tin, low, adj, vis, mark);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
        }
        
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for (auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<bool> vis(n, false);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, tin, low, adj, vis, mark);
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i]) {
                ans.push_back(i);
            }
        }
        return (ans.empty()) ? vector<int>{-1} : ans;
    }
};
