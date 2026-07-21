// Approach 1
// TC = O(E*LOG(V))
// SC = O(V)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for (auto it: times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> time(n + 1, 1e9);
        time[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it: adj[node]) {
                int v = it.first;
                int w = it.second;

                if (time[v] > w + d) {
                    time[v] = w + d;
                    pq.push({time[v], v});
                }
            }
        }

        int maxi = time[k];
        for (int i = 1; i <= n; i++) {
            if (time[i] == 1e9)
                return -1;
            maxi = max(maxi, time[i]);
        }

        return maxi;
    }
};
