// Approach 1
// TC = O(m * n)
// SC = O(1)
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int result = INT_MAX;
        int m = landStartTime.size();
        int n = waterStartTime.size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // land then water
                int landTime = landStartTime[i] + landDuration[i];
                int landToWater = max(landTime, waterStartTime[j]) + waterDuration[j];
                result = min(landToWater, result);

                // water then land
                int waterTime = waterStartTime[j] + waterDuration[j];
                int waterToLand = max(waterTime, landStartTime[i]) + landDuration[i];
                result = min(waterToLand, result);
            }
        }
        return result;
    }
};
