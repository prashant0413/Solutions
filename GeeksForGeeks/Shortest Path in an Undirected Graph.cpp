// Approach 1
// TC = O(E*V*LOG(E))
// SC = O(E*V)
class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

        vector<pair<int,int>> adj[V + 1];

        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // Sort neighbours so lexicographically smaller nodes are explored first
        for (int i = 1; i <= V; i++)
            sort(adj[i].begin(), adj[i].end());

        using T = pair<long long, vector<int>>;

        priority_queue<T, vector<T>, greater<T>> pq;

        vector<long long> dist(V + 1, LLONG_MAX);

        pq.push({0, {src}});
        dist[src] = 0;

        while (!pq.empty()) {

            auto [d, path] = pq.top();
            pq.pop();

            int u = path.back();

            if (u == dest)
                return path;

            if (d > dist[u])
                continue;

            for (auto [v, w] : adj[u]) {

                long long nd = d + w;

                if (nd < dist[v]) {
                    dist[v] = nd;
                    auto np = path;
                    np.push_back(v);
                    pq.push({nd, np});
                }
                else if (nd == dist[v]) {
                    auto np = path;
                    np.push_back(v);
                    pq.push({nd, np});
                }
            }
        }

        return {-1};
    }
};
