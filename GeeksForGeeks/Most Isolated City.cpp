// APPROACH 1: FLOYYD WARSHALL'S ALGORITHM
// TC: O(N^3)
// SC: O(N^2)
class Solution {
  public:
    int findCity(int n, vector<vector<int>>& edges, int dis) {
        // building graph
        vector<vector<int>> graph(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) graph[i][i] = 0;
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u][v] = w;
            graph[v][u] = w;
        }
        
        // floyyd warshall algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (graph[i][via] == 1e9 || graph[via][j] == 1e9) continue;
                    graph[i][j] = min(graph[i][j], graph[i][via] + graph[via][j]);
                }
            }
        }
        
        int mini = n;
        int label = 1;
        for (int i = 0; i < n; i++) {
            int m = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (graph[i][j] <= dis) m++;
            }
            if (m < mini) {
                mini = m;
                label = i;
            } else if (m == mini) label = i;
        }
        
        return label;
    }
};
