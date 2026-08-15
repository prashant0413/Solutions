// Approach 1 using Kosaraju's algorithm
// TC = O(V + E)
// SC = O(N)
class Solution {
  private:
    void dfs(int node, vector<bool> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = true;
        for (int i: adj[node]) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }
        st.push(node);
    }
    
    void redfs(int node, vector<bool> &vis, vector<int> adj[]) {
        vis[node] = true;
        for (int i: adj[node]) {
            if (!vis[i]) {
                redfs(i, vis, adj);
            }
        }
    }
  public:
    int kosaraju(int n, vector<vector<int>> &edges) {
        vector<int> adj[n];
        for (auto it: edges) {
            adj[it[0]].push_back(it[1]);
        }
        
        // applying toposort
        stack<int> st;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }
        
        // reversing edges
        vector<int> transpose[n];
        for (int i = 0; i < n; i++) {
            vis[i] = false;
            for (int it: adj[i]) {
                transpose[it].push_back(i);
            }
        }
        
        // redfs
        int cnt = 0;
        while (!st.empty()) {
            int node = st.top(); st.pop();
            if (!vis[node]) {
                cnt++;
                redfs(node, vis, transpose);
            }
        }
        
        return cnt;
    }
};
