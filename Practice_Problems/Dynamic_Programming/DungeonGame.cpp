class Solution {
public:
    int maxRow, maxCol;
    int dp[201][201];

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp, -1, sizeof(dp));
        maxRow = dungeon.size();
        maxCol = dungeon[0].size();
        return solve(0, 0, dungeon);
    }

    int solve(int row, int col, vector<vector<int>>& dungeon)
    {
        if (row == maxRow - 1 && col == maxCol - 1)
        {
            return dungeon[row][col] <=0 ? -dungeon[row][col] + 1 : 1;
        }
        if (row >= maxRow || col >= maxCol)
        {
            return INT_MAX;
        }

        int& ret = dp[row][col];
        if (ret != -1)
        {
            return ret;
        }

        ret = INT_MAX;

        int down = solve(row+1, col, dungeon);
        int right = solve(row, col+1, dungeon);

        int required = min(down, right) - dungeon[row][col];

        ret = required <= 0 ? 1 : required;
        return ret;
    }
};

// -2  -5   -2
// -7  -15  -1
//  3   33  28 