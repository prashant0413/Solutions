// Approach 1
// TC = O(V * V ^ M)
// SC = O(V + E)
// V = Number of Vertices, M = Number of Colors, E = Number of Edges
class Solution {
    
    bool isSafe(int node, vector<int> &color, vector<vector<bool>> &graph, int col, int v) {
        for (int k = 0; k < v; k++) {
            if (node != k && graph[k][node] && color[k] == col)
                return false;
        }
        return true;
    }
    
    bool solve(int node, vector<vector<bool>> &graph, vector<int> &color, int m, int v) {
        if (node == v) {
            return true;
        }
        
        for (int i = 1; i <= m; i++) {
            if (isSafe(node, color, graph, i, v)) {
                color[node] = i;
                
                if (solve(node + 1, graph, color, m, v))
                    return true;
                color[node] = 0;
            }
        }
        
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<bool>> graph(v, vector<bool>(v, false));
        for (int i = 0; i < edges.size(); i++) {
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            graph[v1][v2] = graph[v2][v1] = true;
        }
        vector<int> color(v, 0);
        return solve(0, graph, color, m, v);
    }
};
