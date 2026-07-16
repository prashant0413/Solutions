// Approach 1
// TC = O(V + E)
// SC = O(V)
class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(V, 0);
        vector<int> adj[V];
        for (auto i: prerequisites) {
            inDegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ordering;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ordering.push_back(node);

            for (int &i: adj[node]) {
                inDegree[i]--;
                if (inDegree[i] == 0) q.push(i);
            }
        }

        reverse(begin(ordering), end(ordering));
        return ordering.size() != V ? vector<int>{} : ordering;
    }
};
