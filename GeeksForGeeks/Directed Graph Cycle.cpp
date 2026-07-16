// Approach 1 using Kahn's Algorithm
// TC = O(V + E)
// SC = O(V)
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        int inDegree[V] = {0};
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
        
        int n = 0;
        while (!q.empty()) {
            int node = q.front();
            n++;
            q.pop();
            
            for (int &i: adj[node]) {
                inDegree[i]--;
                if (inDegree[i] == 0) q.push(i);
            }
        }
        
        return n != V;
    }
};
