class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxProfit = 0;
        int buyPrice = prices[0];
        for (int i = 0; i < n; i++)
        {
            int profit = 0;
            if (buyPrice > prices[i])
                buyPrice = prices[i];
            profit = prices[i] - buyPrice;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
