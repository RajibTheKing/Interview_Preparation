class Solution {
public:
    int dp[202][202];


    int ROW, COL;

    bool isValid(int r, int c)
    {
        if (r >= 0 && r < ROW && c >= 0 && c < COL)
        {
            return true;
        }
        return false;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        memset(dp, -1, sizeof(dp));

        int maxAns = -1;
        ROW = matrix.size();
        COL = matrix[0].size();

        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                maxAns = max(maxAns, solve(i, j, matrix));
            }
        }

        return maxAns;
    }

    int solve(int row, int col, vector<vector<int>>& matrix)
    {
        int& ret = dp[row][col];
        if (ret != -1)
        {
            return ret;
        }

        ret = 1;
        int now = matrix[row][col];
        int maxSol = 0;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nx = row + dx[i];
            int ny = col + dy[i];
            if (isValid(nx, ny) && matrix[nx][ny] > now)
            {
                maxSol = max(maxSol, solve(nx, ny, matrix));
            }
        }
        ret = ret + maxSol;
        return ret;
    }
};