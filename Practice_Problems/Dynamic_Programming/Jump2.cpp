class Solution {
public:
    int dp[10000 + 1];
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }

    int solve(int cur, vector<int>& nums)
    {
        if(cur >= nums.size() - 1)
            return 0;
        int step = nums[cur];

        int& ret = dp[cur];

        if(ret != -1)
            return ret;

        ret = 100000;

        for(int i=1; i<=step; i++)
        {
            int next = cur + i;
            ret = min(ret, 1 + solve(next, nums));
        }

        return ret;
    }
};