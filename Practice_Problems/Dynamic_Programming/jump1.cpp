class Solution {
public:
    int dp[10000 + 1];
    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums);
    }

    bool solve(int cur, vector<int>& nums)
    {

        if(cur >= nums.size() - 1)
        {
            return true;
        }

        int& ret = dp[cur];
        if(ret != -1)
        {
            return ret == 1;
        }

        ret = 0;
        int step = nums[cur];
        for(int i=1; i<=step; i++)
        {
            if(solve(cur+i, nums) == true)
            {
                ret = 1;
                return true;
            }
        }

        return false;
    }
};