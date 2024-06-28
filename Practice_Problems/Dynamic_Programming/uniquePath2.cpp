class Solution {
public:
    int dp[101][101];

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                dp[i][j] = -1;
        return solve(0, 0, m, n, obstacleGrid);    
    }

    int solve(int row, int col, int m, int n, vector<vector<int>>& obstacleGrid)
    {
        if(row == m - 1 && col == n - 1 && obstacleGrid[row][col] == 0)
        {
            return 1;
        }

        if(row >= m || col >= n)
        {
            return 0;
        }

        if(obstacleGrid[row][col] == 1)
        {
            return 0;
        }

        int& ret = dp[row][col];
        if(ret != -1)
        {
            return ret;
        }
        ret = 0;
        ret += solve(row+1, col, m, n, obstacleGrid);
        ret += solve(row, col+1, m, n, obstacleGrid);

        return ret;
    }
};