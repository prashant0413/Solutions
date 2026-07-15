// Approach 1
// TC = O(V + 2E)
// SC = O(V)
class Solution {
public:
    bool dfs(int node, vector<bool> &vis, vector<bool> &pathVis,  vector<int> adj[]) {
        vis[node] = true;
        pathVis[node] = true;
        for (int &i: adj[node]) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) {
                    return true;
                }
            } else {
                if (pathVis[i]) return true;
            }
        }
        pathVis[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) return false;
            }
        }
        return true;
    }
};
