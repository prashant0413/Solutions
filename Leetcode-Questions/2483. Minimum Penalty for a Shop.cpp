// Approach 1
// TC = O(n ^ 2)
// SC = O(1)
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int minPenalty = INT_MAX;
        int minHour = INT_MAX;
        for (int i = 0; i <= n; i++) {
            int penalty = 0;
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    penalty += (customers[j] == 'N') ? 1 : 0;
                } else {
                    penalty += (customers[j] == 'Y') ? 1 : 0;
                }
            }
            if (penalty < minPenalty) {
                minPenalty = penalty;
                minHour = i;
            }
        }
        return minHour;
    }
};
