class Solution {
public:

    int dp[201][201];
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0; i<triangle.size(); i++)
            for(int j=0; j<triangle[i].size(); j++)
                dp[i][j] = INT_MAX;

        return solve(0, 0, triangle);
    }

    int solve(int curLevel, int currentIndex, vector<vector<int>>& triangle)
    {
        if (curLevel == triangle.size())
        {
            return 0;
        }

        if (currentIndex >= triangle[curLevel].size())
        {
            return INT_MAX;
        }

        int& ret = dp[curLevel][currentIndex];
        if (ret != INT_MAX)
        {
            return ret;
        }
        int val = triangle[curLevel][currentIndex];
        ret = min(ret, val + solve(curLevel+1, currentIndex, triangle));
        ret = min(ret, val + solve(curLevel+1, currentIndex+1, triangle));

        return ret;
    }
};