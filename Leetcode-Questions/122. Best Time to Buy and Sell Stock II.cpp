// APPROACH 1:
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int maxProfit = 0;
        int stock = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] > stock) {
                maxProfit += (prices[i] - stock);
                stock = prices[i];
            } else {
                stock = prices[i];
            }
        }

        return maxProfit;
    }
};
