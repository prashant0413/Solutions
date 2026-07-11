// Approach 1
// TC = O(V + 2E)
// SC = O(V)
class Solution {
  public:
    bool detect(vector<int> adjList[], int v, int st, vector<bool> &vis) {
        vis[st] = true;
        queue<pair<int, int>> q;
        q.push({st, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (int &p: adjList[node]) {
                if (!vis[p]) {
                    q.push({p, node});
                    vis[p] = true;
                } else if (parent != p) {
                    return true;
                }
            }
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> adjList[V];
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(adjList, V, i, vis)) return true;
            }
        }
        
        return false;
    }
};
