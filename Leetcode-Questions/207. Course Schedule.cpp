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

// APPROACH 2: USING TOPOLOGICAL SORT
// TC: O(V + E)
// SC: O(V)
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for (auto it: prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        int inDegree[numCourses];
        for (int i = 0; i < numCourses; i++) inDegree[i] = 0;
        for (int i = 0; i < numCourses; i++) {
            for (int it: adj[i]) {
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }
        
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            cnt++;
            for (int i: adj[node]) {
                inDegree[i]--;
                if (inDegree[i] == 0) q.push(i);
            }
        }
        
        return (cnt == numCourses);
    }
};
