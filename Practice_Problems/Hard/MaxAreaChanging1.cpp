class Solution {
public:
    map<int, int> mp;
    int memoMarker[501][501];
    int color[501][501];
    int n, m;
    int largestIsland(vector<vector<int>>& grid)
    {
        memset(color, -1, sizeof(color));
        n = grid.size();
        m = grid[0].size();
        int marker = 1;
        int maxArea = 0;
        int dx[] = {1, 0, -1,  0};
        int dy[] = {0, 1,  0, -1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && color[i][j] == -1)
                {
                    marker++;
                    int value = BFS(i, j, grid, marker);
                    mp[marker] = value;
                    maxArea = max(maxArea, value);
                }
            }
        }


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    set<int> st;
                    int currentMax = 1;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < m && st.find(memoMarker[nx][ny]) == st.end())
                        {
                            currentMax += mp[memoMarker[nx][ny]];
                            st.insert(memoMarker[nx][ny]);
                        }
                    }
                    maxArea = max(maxArea, currentMax);
                }
            }
        }

        return maxArea;

    }

    int BFS(int row, int col, vector<vector<int>>& grid, int marker)
    {
        int cnt = 0;
        queue<int> Q;
        Q.push(row);
        Q.push(col);
        color[row][col] = 1;
        memoMarker[row][col] = marker;

        int dx[] = {1, 0, -1,  0};
        int dy[] = {0, 1,  0, -1};

        while(!Q.empty())
        {
            cnt++;
            int x = Q.front(); Q.pop();
            int y = Q.front(); Q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == 1 && color[nx][ny] == -1)
                {
                    Q.push(nx);
                    Q.push(ny);
                    color[nx][ny] = 1;
                    memoMarker[nx][ny] = marker;
                }
            }
        }

        return cnt;

    }
};

// 0 1 1 1
// 0 1 0 1
// 0 1 1 1
// 0 0 0 0