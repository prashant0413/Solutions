// Approach 1 using floyd warshall algorithm
// TC = O(n^3)
// SC = O(n^2)
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][via] == 1e9 || dist[via][j] == 1e9) continue;
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }

        int min = INT_MAX;
        int node = -1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist[i][j] <= distanceThreshold) {
                    cnt += 1;
                }
            }
            if (cnt <= min) {
                if (cnt < min)
                    min = cnt;
                node = i;
            }
        }

        return node;
    }
};

// Approach 2 using Dijkstra Algorithm
// TC = O(V*E*LOG(V))
// SC = O(V)
class Solution {
public:
    vector<int> dijkstra(int n , vector<vector<int>> &dist, int src,  vector<pair<int, int>> adj[]) {
        vector<int> distance(n, 1e9);
        distance[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > distance[node]) continue;
            
            for (auto i: adj[node]) {
                int v = i.first;
                int w = i.second;

                if (d + w < distance[v]) {
                    distance[v] = d + w;
                    pq.push({d + w, v});
                }
            }
        }
        return distance;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int i = 0; i < n; i++) dist[i][i] = 0;

        vector<pair<int, int>> adj[n];
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        for (int i = 0; i < n; i++) {
            dist[i] = dijkstra(n, dist, i, adj);
        }

        int min = INT_MAX;
        int node = -1;

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (dist[i][j] <= distanceThreshold) {
                    cnt += 1;
                }
            }
            
            if (cnt <= min) {
                if (cnt < min)
                    min = cnt;
                node = i;
            }
        }

        return node;
    }
};
