class Solution {
public:
    static const int maxLimit = 12;
    int minMinute[maxLimit][maxLimit];
    int dx[4] = {0,  0, 1, -1};
    int dy[4] = {1, -1, 0,  0};
    int row, col;
    int tracker[maxLimit][maxLimit];

    int orangesRotting(vector<vector<int>>& grid)
    {
        row = grid.size();
        col = grid[0].size();
        for (int i = 0; i < maxLimit; i++)
        {
            for (int j = 0; j < maxLimit; j++)
            {
                minMinute[i][j] = maxLimit * maxLimit;
                tracker[i][j] = 0;
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 2)
                {
                    //this is a rotten orange
                    doBFS(grid, i, j);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(grid[i][j] == 1 && tracker[i][j] == 0)
                    return -1;
                if(tracker[i][j] == 1)
                {
                    ans = max(ans, minMinute[i][j]);
                }
            }
        }
        return ans;
    }

    void doBFS(vector<vector<int>>& grid, int x, int y)
    {
        int color[row][col];
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                color[i][j] = 0;
        queue<int> Q;
        Q.push(x);
        Q.push(y);
        Q.push(0);
        color[x][y] = 1;

        while (!Q.empty())
        {
            x = Q.front(); Q.pop();
            y = Q.front(); Q.pop();
            int m = Q.front(); Q.pop();
            tracker[x][y] = 1;
            //cout << "Now: " << x << ", " << y << ", " << m << endl;
            minMinute[x][y] = min(minMinute[x][y], m);
            for (int i = 0; i < 4; i++)
            {
                int nextX = x + dx[i];
                int nextY = y + dy[i];
                if((nextX >= 0 && nextX < row) && (nextY >= 0 && nextY < col))
                {
                    if(color[nextX][nextY] == 0)
                    {
                        color[nextX][nextY] = 1;
                        if (grid[nextX][nextY] == 1 || grid[nextX][nextY] == 2)
                        {
                            Q.push(nextX);
                            Q.push(nextY);
                            Q.push(m + 1);
                        }
                    }
                }
            }
        }

    }
};