// Approach 1
// TC = O(v) + O(2e)
// SC = O(v)
class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<bool> visited(v, false);
        vector<int> result;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int i = q.front(); q.pop();
            result.push_back(i);
            for (int &k: adj[i]) {
                if (visited[k]) continue;
                q.push(k);
                visited[k] = true;
            }
        }
        return result;
    }
};
