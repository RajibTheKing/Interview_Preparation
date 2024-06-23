class Solution {
public:
    int dp[101];
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s);
    }

    int solve(int cur, string& s)
    {
        if (cur == s.size())
        {
            return 1;
        }

        int& ret = dp[cur];
        if (ret != -1)
        {
            return ret;
        }

        int now = s[cur] - '0';
        int a = 0, b = 0;
        if (now != 0)
        {
            a = solve(cur+1, s);
        }
        if(cur+1 < s.size() && now != 0)
        {
            int next = s[cur+1] - '0';
            int combined = now * 10 + next;
            //printf("combined: %d\n", combined);
            if(combined <= 26)
            {
                b = solve(cur + 2, s);
            }
        }
        ret = a + b;
        return ret;
    }
};