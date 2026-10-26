// APPROACH 1: USING SORTING AND MAX-HEAP
// TC: O(N LOG N)
// SC: O(N)
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({capital[i], profits[i]});
        }

        sort(begin(arr), end(arr));
        priority_queue<int> pq;
        int i = 0;
        while ((i < n || !pq.empty()) && k > 0) {
            if (i < n && pq.empty() && w < arr[i].first) break;

            while (i < n && w >= arr[i].first) {
                pq.push(arr[i].second);
                i++;
            }

            if (!pq.empty()) {
                int profit = pq.top(); pq.pop();
                w += profit;
                k--;
            }
        }

        return w;
    }
};
