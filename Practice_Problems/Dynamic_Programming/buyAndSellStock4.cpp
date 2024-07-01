class Solution {
public:
    int dp[1001][101];

    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(0, k, prices);    
    }

    int solve(int cur, int k, vector<int>& prices)
    {
        if (k == 0 || cur == prices.size())
        {
            return 0;
        }

        int& ret = dp[cur][k];
        if (ret != -1)
        {
            return ret;
        }
        ret = 0;

        int max1 = 0, max2 = 0, profit = 0;

        for (int i= cur + 1; i < prices.size(); i++)
        {
            profit += prices[i] - prices[i-1];
            max1 = max(profit, max1);
            if (profit < 0)
                profit = 0;
            max2 = solve(i+1, k-1, prices);
            ret = max(ret, max1+max2);
        }

        return ret;
    }
};