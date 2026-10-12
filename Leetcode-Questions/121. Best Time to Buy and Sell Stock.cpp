// APPROACH 1: 
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int profit = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};
