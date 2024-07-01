class Solution {
public:
    int dp[302][302];
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        return solve(0, n-1, nums);
    }

    int solve(int left, int right, vector<int>& nums)
    {
        if(left == right)
        {
            int leftValue = left == 0 ? 1 : nums[left - 1];
            int rightValue = right == nums.size() - 1 ? 1 : nums[right + 1];
            return leftValue * nums[left] * rightValue;
        }

        if(left > right)
        {
            return 0;
        }

        int& ret = dp[left][right];
        if (ret != -1)
        {
            return ret;
        }

        ret = 0;

        for (int i=left; i <= right; i++)
        {
            int lastToBurst = nums[i];
            int leftValue = left == 0 ? 1 : nums[left-1];
            int rightValue = right == nums.size() - 1 ? 1 : nums[right+1];

            int subProblemLeft = solve(left, i-1, nums);
            int subProblemRight = solve(i+1, right, nums);

            ret = max(ret, subProblemLeft + subProblemRight + leftValue * lastToBurst * rightValue);
        }

        return ret;
    }
};

// [1, 2, 3, 4]
// 24 + 8 + 4 + 4  = 40
//  3   2   1   4

// 1 2 6 24

// level 0: 1 * 300

// level 1: 300 * 299

// level 2: 299 * 298

// level 3: 298 * 297

// 1 5 8
// 40 +
