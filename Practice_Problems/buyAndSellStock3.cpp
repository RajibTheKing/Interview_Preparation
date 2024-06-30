class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> maxProfitFromRight(n, 0);

        int maxPrice = 0;
        int maxProfit = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            maxPrice = max(maxPrice, prices[i]);
            maxProfit = max(maxProfit, maxPrice - prices[i]);
            maxProfitFromRight[i] = maxProfit;
        }

        vector<int> maxProfitFromLeft(n, 0);
        int minPrice = INT_MAX;

        maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
            maxProfitFromLeft[i] = maxProfit;
        }

        int maxTotalPrice = 0;
        for (int i = 0; i < n - 1; i++)
        {
            maxTotalPrice = max(maxTotalPrice, maxProfitFromLeft[i] + maxProfitFromRight[i+1]);
        }
        maxTotalPrice = max(maxTotalPrice, maxProfitFromLeft[n-1]);

        return maxTotalPrice;
    }
};


