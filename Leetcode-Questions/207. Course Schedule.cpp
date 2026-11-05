// APPROACH 1: DFS DIRECTED CYCLE DETECTION
// TC: O(V + E)
// SC: O(V)
class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis) {
        vis[node] = true;
        pathVis[node] = true;
         for (int i: adj[node]) {
            if (vis[i] && pathVis[i]) return false;
            if (vis[i]) continue;
            if (!dfs(i, adj, vis, pathVis)) return false;
        }

        pathVis[node] = false;
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto prerequisite: prerequisites) {
            adj[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> pathVis(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (vis[i]) continue;
            if (!dfs(i, adj, vis, pathVis)) return false;
        }

        return true;
    }
};
