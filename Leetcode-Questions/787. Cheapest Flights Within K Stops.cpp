// Approach 1
// TC = O(E)
// SC = O(E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto i: flights) {
            int u = i[0];
            int v = i[1];
            int cost = i[2];
            adj[u].push_back({v, cost});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto it = q.front(); q.pop();
            int steps = it.first;
            int node = it.second.first;
            int w = it.second.second;

            if (steps > k) continue;
            
            for (auto it: adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (dist[v] > wt + w && steps <= k) {
                    dist[v] = wt + w;
                    q.push({steps + 1, {v, dist[v]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
