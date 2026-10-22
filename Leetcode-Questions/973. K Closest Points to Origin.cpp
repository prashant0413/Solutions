// APPROACH 1: USING MAX-HEAP
// TC: O(N LOG K)
// SC: O(K)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            double distance = sqrt((x * x + y * y));
            pq.push({distance, i});
            if (pq.size() > k) pq.pop();
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }        

        return result;
    }
};
