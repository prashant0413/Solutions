// APPROACH 1: BFS TRAVERSAL 
// TC: O(N * E)
// SC: O(N * E)
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, false);
        visited[source] = true;
        queue<int> q;
        for (int i: adj[source]) {
            visited[i] = true;
            q.push(i);
        }

        if (visited[destination]) return true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int i: adj[v]) {
                if (visited[i]) continue;
                visited[i] = true;
                q.push(i);
                if (visited[destination]) return true;
            }
        }

        return visited[destination];
    }
};


// APPROACH 2: DFS TRAVERSAL
// TC: O(N * E)
// SC: O(N * E)
class Solution {
public:
    bool dfs(int source, vector<int> adj[], vector<bool> &visited, int destination) {
        visited[source] = true;
        for (int i: adj[source]) {
            if (visited[i]) continue;
            visited[i] = true;
            if (visited[destination]) return true;
            if (dfs(i, adj, visited, destination)) return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        vector<int> adj[n];
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        return dfs(source, adj, visited, destination);
    }
};
