class Solution {
public:
    int dp[201][201][2];

    bool isInterleave(string s1, string s2, string s3)
    {
        for (int i=0; i<=s1.size(); i++)
        {
            for (int j=0; j<=s2.size(); j++)
            {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }

        return (solve(0, 0, s1, s2, s3, 0) | solve(0, 0, s1, s2, s3, 1)) == 1;
    }

    int solve(int s1Pos, int s2Pos, string& s1, string& s2, string& s3, int flag)
    {
        // for(int i=0; i<s1Pos+s2Pos; i++)
        // {
        //     cout << "  ";
        // }
        // cout << s1Pos << ", " << s2Pos << ", " << flag << endl;
        if (s1Pos == s1.size() && s2Pos == s2.size() && s1Pos + s2Pos == s3.size())
        {
            return 1;
        }

        if (s1Pos == s1.size() && s2Pos == s2.size() && s1Pos + s2Pos != s3.size())
        {
            return 0;
        }

        if (s1Pos + s2Pos == s3.size())
        {
            return 0;
        }

        int& ret = dp[s1Pos][s2Pos][flag];
        if (ret != -1)
        {
            return ret;
        }

        ret = 0;

        if (flag == 0)
        {
            int s3Pos = s1Pos + s2Pos;
            for (int i = s1Pos, j = s3Pos; i < s1.size() && j < s3.size(); i++, j++)
            {
                if (s3[j] == s1[i])
                {
                    ret |= solve(i+1, s2Pos, s1, s2, s3, 0);
                }
                else
                {
                    break;
                }
            }
            if (s3[s3Pos] == s2[s2Pos])
            {
                ret |= solve(s1Pos, s2Pos + 1, s1, s2, s3, 1);
            }
        }
        else
        {
            int s3Pos = s1Pos + s2Pos;
            for (int i = s2Pos, j = s3Pos; i < s2.size() && j < s3.size(); i++, j++)
            {
                if (s3[j] == s2[i])
                {
                    ret |= solve(s1Pos, i+1, s1, s2, s3, 1);
                }
                else
                    break;
            }
            if (s3[s3Pos] == s1[s1Pos])
            {
                ret |= solve(s1Pos + 1, s2Pos, s1, s2, s3, 0);
            }
        }

        return ret;

    }
};