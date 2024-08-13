class Solution {
public:
    int dp[12][2][12];

    int solve(string& s, int pos, int tight, int cnt)
    {
        if (pos == s.size())
            return cnt;

        int& res = dp[pos][tight][cnt];

        if (res != -1)
            return res;

        res=0;

        int limit = tight ? (s[pos] - '0') : 9;

        for (int i = 0; i <= limit; i++)
        {
            int updateCnt = cnt + (i == 1 ? 1 : 0); // count if digit 1 is found
            res += solve(s, pos+1, tight & (i == limit), updateCnt);
        }

        return res;
    }

    int countDigitOne(int n)
    {
        memset(dp, -1, sizeof(dp));
        string num = to_string(n);
        return solve(num, 0, 1, 0);
    }
};

// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13

// total: 6 times
