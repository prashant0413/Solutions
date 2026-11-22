// APPROACH 1: 
// TC: O(N)
// SC: O(1)
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int buy = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            maxProfit = max(maxProfit, prices[i] - buy);
            if (prices[i] < buy) buy = prices[i];
        }
        
        return maxProfit;
    }
};
