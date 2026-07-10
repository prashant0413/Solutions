// Approach 1
// TC = O(2e)
// SC = O(v)
class Solution {
  public:
    void solve(int i, vector<bool> &vis, vector<int> &res, vector<vector<int>>& adj) {
        res.push_back(i);
        for (int &k: adj[i]) {
            if (vis[k]) continue;
            vis[k] = true;
            solve(k, vis, res, adj);
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> vis(v, false);
        vector<int> res;
        vis[0] = true;
        solve(0, vis, res, adj);
        return res;
    }
};
