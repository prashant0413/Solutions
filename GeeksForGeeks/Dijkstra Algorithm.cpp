// Approach 1 using priority queue
// TC = O((V + E)LOG(V))
// SC = O(V)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int, int>> adj[V];
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for (auto it: adj[node]) {
                int v = it.first;
                int w = it.second;
                
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        
        return dist;
    }
};

// Approach 2 using set
// TC = O((V + E)LOG(V))
// SC = O(V)
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<pair<int, int>> adj[V];
        for (auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        set<pair<int, int>> st;
        st.insert({0, src});
        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int w = it.first;
            st.erase(it);
            
            for (auto i: adj[node]) {
                int v = i.first;
                int wt = i.second;
                
                if (dist[v] == 1e9) {
                    dist[v] = w + wt;
                    st.insert({dist[v], v});
                } else {
                    if (wt + w < dist[v]) {
                        st.erase({dist[v], v});
                        dist[v] = wt + w;
                        st.insert({dist[v], v});
                    }
                }
            }
        }
        
        return dist;
    }
};
