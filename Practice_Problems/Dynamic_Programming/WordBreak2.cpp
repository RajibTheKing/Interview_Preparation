class Solution {
public:
    map<string, bool> mp;
    map<string, vector<string>> dp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++)
        {
            mp[wordDict[i]] = true;
        }
        return solve(s);
    }

    vector<string> solve(string s)
    {
        if (s.size() == 0)
        {
            vector<string> ret;
            return ret;
        }

        if (dp.find(s) != dp.end())
        {
            return dp[s];
        }

        vector<string> ans;

        if(mp.find(s) != mp.end())
        {
            ans.push_back(s);
        }

        for (int i=1; i<s.size(); i++)
        {
            string left = s.substr(0, i);
            if(mp.find(left) != mp.end())
            {
                string right = s.substr(i, s.size()-i);
                vector<string> part =  solve(right);
                for(int j=0; j<part.size(); j++)
                {
                    if(part[j].size() > 0)
                    {
                        string now = left + " " + part[j];
                        ans.push_back(now);
                    }
                }
            }
        }

        dp[s] = ans;
        return dp[s];
    }
};