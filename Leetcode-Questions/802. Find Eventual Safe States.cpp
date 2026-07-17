// Approach 1
// TC = O(V + E)
// SC = O(V)
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adj[V];
        int inDegree[V];
        for (int i = 0; i < V; i++) inDegree[i] = 0;
        for (int i = 0; i < V; i++) {
            for (int &it: graph[i]) {
                adj[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i: adj[node]) {
                if (--inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
