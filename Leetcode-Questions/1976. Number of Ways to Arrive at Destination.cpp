// Approach 1
// TC = O(E * LOG(V))
// SC = O(V)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int, int>> adj[n];
        for (auto it: roads) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        int mod = 1e9 + 7;

        priority_queue<pair<long long,int>,
        vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        pq.push({0, 0});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            long long d = it.first;

            for (auto i: adj[node]) {
                int v = i.first;
                int w = i.second;

                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({d + w, v});
                    ways[v] = ways[node] % mod;
                } else if (d + w == dist[v]) {
                    ways[v] = (ways[node] + ways[v]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
