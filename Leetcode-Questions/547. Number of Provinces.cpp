// Approach 1
// TC = O(V) + O(V + 2E)
// SC = O(V)
class Solution {
public:
    void bfs(int st, vector<vector<int>>& isConnected, vector<bool> &vis, int v) {
        queue<int> q;
        q.push(st);
        while (!q.empty()) {
            int k = q.front(); q.pop();
            for (int j = 0; j < v; j++) {
                if (k == j || vis[j]) continue;
                if (isConnected[k][j]) {
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int cnt = 0;
        vector<bool> vis(v, false);
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                vis[i] = true;
                cnt++;
                bfs(i, isConnected, vis, v);
            }
        }
        return cnt;
    }
};
