// Approach 1
// TC = O(n * min(x, y))
// SC = O(1)
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int x, y;
        int minStep = 0;
        for (int i = 1; i < n; i++) {
            x = abs(points[i][0] - points[i - 1][0]);
            y = abs(points[i][1] - points[i - 1][1]);
            if (x == 0 || y == 0) {
                minStep += x + y;
            } else {
                while (x != 0 && y != 0) {
                    minStep += 1;
                    x--;
                    y--;
                }
                minStep += x + y;
            }
        }
        return minStep;
    }
};
