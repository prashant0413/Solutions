// Approach 1
// TC = O(V + 2E)
// SC = O(V)
class Solution {
    bool dfs(int node, int col, int color[], vector<vector<int>>& graph) {
        color[node] = col;
        for (int &i: graph[node]) {
            if (color[i] == -1) {
                if (!dfs(i, 1 - col, color, graph)) {
                    return false;
                }
            } else {
                if (color[i] == col) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for (int i = 0; i < V; i++) color[i] = -1;
        
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};
