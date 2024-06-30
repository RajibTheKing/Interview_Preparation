class Solution {
public:
    map<string, bool> mp;
    map<string, bool> dp;

    bool wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++)
        {
            mp[wordDict[i]] = true;
        }
        return solve(s);
    }

    bool solve(string s)
    {
        if (s.size() == 0)
        {
            return false;
        }

        if (dp.find(s) != dp.end())
        {
            return dp[s];
        }

        bool ans = false;

        if(mp.find(s) != mp.end())
        {
            ans = true;
        }
        else
        {
            for (int i=1; i<s.size(); i++)
            {
                string left = s.substr(0, i);
                if(mp.find(left) != mp.end())
                {
                    string right = s.substr(i, s.size()-i);
                    ans |= solve(right);
                }
            }
        }
        dp[s] = ans;
        return dp[s];
    }
};