class Solution {
public:
    int dp[46];

    int climbStairs(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }

    int solve(int n)
    {
        if (n == 0)
        {
            return 1;
        }
        int& ret = dp[n];
        if(ret != -1)
            return ret;
        ret = 0;
        int oneStep = solve(n-1);
        int twoStep = 0;

        if (n >= 2)
        {
            twoStep = solve(n-2);
        }
        ret = oneStep + twoStep;
        return ret;
    }
};