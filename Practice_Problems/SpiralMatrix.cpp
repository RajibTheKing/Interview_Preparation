class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        //  down --> left --> up --> right
        int dx[] = {1,  0, -1, 0};
        int dy[] = {0, -1,  0, 1};
        
        int STOP = 9999; // just a number which indicates cell is already visited, range is -100 <= v <= 100
        int direction = 3; // initially we go right direction

        int totalNumbers = matrix.size() * matrix[0].size();

        vector<int> ans;
        int row = 0;
        int col = 0;

        while (totalNumbers--)
        {
            ans.push_back(matrix[row][col]);
            matrix[row][col] = STOP;
            int nx = row + dx[direction];
            int ny = col + dy[direction];
            if(isValid(nx, ny, matrix) && matrix[nx][ny] != STOP)
            {
                row = nx;
                col = ny;
            }
            else
            {
                direction++;
                direction %= 4;
                row = row + dx[direction];
                col = col + dy[direction];
            }
        }
        return ans;
    }

    bool isValid(int row, int col, vector<vector<int>>& matrix)
    {
        return row >= 0 && row < matrix.size() && col >=0 && col < matrix[0].size();
    }
};