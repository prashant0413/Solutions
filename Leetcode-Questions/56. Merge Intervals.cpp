// Approach 1
// TC: O(N log N)
// SC: O(N)
class Solution {
public:
    struct cmp {
        bool operator()(vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        }
    };

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(begin(intervals), end(intervals), cmp());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            if (res.back()[1] >= intervals[i][0]) {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
