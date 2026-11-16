// APPROACH 1: USING KRUSHKAL ALGORITHM
// TC: O(V^2) + O(E LOG E)
// SC: O(V + E)
class DisjointSet {
    vector<int> size;
    vector<int> parent;
public:
    DisjointSet(int n) {
        size = vector<int>(n, 1);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUpar(int node) {
        return node == parent[node] ? node : parent[node] = findUpar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int up_u = findUpar(u);
        int up_v = findUpar(v);
        if (up_u == up_v) return;
        if (size[up_u] < size[up_v]) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
private:
    int krushkal(int V, vector<vector<int>> edges) {
        DisjointSet ds(V);
        auto cmp = [](auto &p1, auto &p2) {
            return p1[2] < p2[2];
        };
        sort(begin(edges), end(edges), cmp);

        int cost = 0;
        int cnt = 0;
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (ds.findUpar(u) != ds.findUpar(v)) {
                cnt++;
                cost += w;
                ds.unionBySize(u, v);
            }
            if (cnt == V - 1) break;
        }

        return cost;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < V; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int w = abs(x1 - x2) + abs(y1 - y2);

                edges.push_back({i, j, w});
            }
        }

        return krushkal(V, edges);
    }
};

// APPROACH 2: PRIM'S ALGORITHM
// TC: O(V^2 LOG V)
// SC: O(V^2)
class Solution {
private:
    int prims(vector<vector<int>> &edges, int V) {
        vector<pair<int, int>> adj[V];
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int cost = 0;
        vector<bool> vis(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (vis[node]) continue;
            vis[node] = true;
            cost += d;
            for (auto it: adj[node]) {
                int v = it.first;
                int w = it.second;
                if (vis[v]) continue;
                pq.push({w, v});
            }
        }

        return cost;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < V; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int w = abs(x1 - x2) + abs(y1 - y2);
                edges.push_back({i, j, w});
            }
        }

        return prims(edges, V);
    }
};
