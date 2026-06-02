// Approach 1
// TC = O(nlog(n))
// SC = O(n)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        vector<array<int, 3>> sortedTasks;
        for (int i = 0; i < n; i++) {
            int time = tasks[i][0];
            int duration = tasks[i][1];
            sortedTasks.push_back({time, duration, i});
        }
        sort(begin(sortedTasks), end(sortedTasks));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        long long time = 0;
        int idx = 0;
        vector<int> res;
        while (idx < n || !pq.empty()) {
            if (pq.empty() && time < sortedTasks[idx][0]) {
                time = sortedTasks[idx][0];
            }

            while (idx < n && sortedTasks[idx][0] <= time) {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            pair<int, int> t = pq.top(); pq.pop();
            time += t.first;
            res.push_back(t.second);
        }
        return res;
    }
};
