// APPROACH 1: USING SORTING AND HEAP
// TC: O(N LOG N)
// SC: O(N)
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n = trips.size();

        auto cmp = [](auto &p1, auto &p2) {
            return p1[1] < p2[1];
        };
        sort(begin(trips), end(trips), cmp);

        int total = trips[0][0];
        if (total > capacity) return false;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({trips[0][2], trips[0][0]});
        for (int i = 1; i < n; i++) {
            while (!pq.empty() && pq.top().first <= trips[i][1]) {
                total -= pq.top().second;
                pq.pop();
            }
            total += trips[i][0];
            pq.push({trips[i][2], trips[i][0]});
            if (total > capacity) return false;
        }

        return true;
    }
};
