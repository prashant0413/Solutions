// APPROACH 1
// TC: O(N LOG N)
// SC: O(1)
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();

        sort(begin(points), end(points));
        vector<int> prev = points[0];
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (prev[1] < points[i][0]) {
                cnt++;
                prev = points[i];
            } else {
                prev[0] = max(prev[0], points[i][0]);
                prev[1] = min(prev[1], points[i][1]);
            }
        }

        return cnt;
    }
};
