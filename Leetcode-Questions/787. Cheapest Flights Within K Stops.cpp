// APPROACH 1: DIJKSTRA ALGORITHM
// TC: O(E)
// SC: O(E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto flight: flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }        

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>> q;

        // {stops, {node, dist}}
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto it = q.front(); q.pop();
            int stops = it.first;
            int node = it.second.first;
            int d = it.second.second;

            for (auto i: adj[node]) {
                int adjNode = i.first;
                int edgeWeight = i.second;
                if (d + edgeWeight < dist[adjNode] && stops <= k) {
                    dist[adjNode] = d + edgeWeight;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
