// Approach 1 using DFS
// TC = O(V + E)
// SC = O(V)
class Solution {
    stack<int> st;
    
    void dfs(int node, vector<bool> &vis, vector<int> adj[]) {
        vis[node] = true;
        for (int &i: adj[node]) {
            if (!vis[i]) {
                dfs(i, vis, adj);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> adj[V];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj);
            }
        }
        
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};

// Approach 1 using BFS (Kahn's Algorithm)
// TC = O(V + E)
// SC = O(V)
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> inDegree(V, 0);
        vector<int> adj[V];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            inDegree[v]++;
            adj[u].push_back(v);
        }
        
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> res;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for (int &i: adj[node]) {
                inDegree[i]--;
                if (inDegree[i] == 0)
                    q.push(i);
            }
        }
        
        return res;
    }
};
