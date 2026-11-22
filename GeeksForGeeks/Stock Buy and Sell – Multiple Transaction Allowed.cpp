// APPRAOCH 1:
// TC: O(N)
// SC: O(1)
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int stock = prices[0];
        int maxProfit = 0;
        int currentProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - stock;
            if (profit < currentProfit) {
                stock = prices[i];
                maxProfit += currentProfit;
                currentProfit = 0;
            } else {
                currentProfit = profit;
            }
        }
        
        return maxProfit + currentProfit;
    }
};
