// Approach 1
// TC = O(2(m+n))
// SC = O(1)
class Solution {
public:
    int solve(vector<int> &actTime1, vector<int> &actDuration1, vector<int> &actTime2, vector<int> &actDuration2) {
        int m = actTime1.size();
        int n = actTime2.size();
        int result = INT_MAX;
        int time1 = INT_MAX;
        for (int i = 0; i < m; i++) {
            time1 = min(actTime1[i] + actDuration1[i], time1);
        }

        for (int i = 0; i < n; i++) {
            int res = max(time1, actTime2[i]) + actDuration2[i];
            result = min(result, res);
        }

        return result;
    }

    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int result1 = solve(landStartTime, landDuration, waterStartTime, waterDuration);
        int result2 = solve(waterStartTime, waterDuration, landStartTime, landDuration);
        return min(result1, result2);
    }
};
