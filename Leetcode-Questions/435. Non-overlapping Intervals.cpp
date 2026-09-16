// APPROACH 1
// TC: O(N LOG N)
// SC: O(1)
class Solution {
public:
    struct cmp {
        bool operator()(vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        }
    };

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals), cmp());

        int cnt = 1;
        int lastEndTime = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEndTime) {
                cnt++;
                lastEndTime = intervals[i][1];
            }
        }

        return n - cnt;
    }
};
