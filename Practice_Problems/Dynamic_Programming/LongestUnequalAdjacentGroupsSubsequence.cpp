class Solution {
public:

    map<int, vector<string>> mp[2];

    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans1 = solve(0, 0, words, groups);
        vector<string> ans2 = solve(0, 1, words, groups);
        return ans1.size() > ans2.size() ? ans1 : ans2;
    }

    vector<string> solve(int cur, int prevGroup, vector<string>& words, vector<int>& groups)
    {
        if(cur == words.size()-1)
        {
            vector<string> ret;
            if(groups[cur] != prevGroup)
            {
                ret.push_back(words[cur]);
            }
            return ret;
        }

        if (mp[prevGroup].find(cur) != mp[prevGroup].end())
        {
            return mp[prevGroup][cur];
        }

        int maxLength = -1;
        vector<string> ans;

        for(int i = cur; i < words.size(); i++)
        {
            if (groups[i] != prevGroup)
            {
                vector<string> now;
                now.clear();
                now.push_back(words[i]);
                vector<string> next = solve(i + 1, prevGroup ^ 1 , words, groups);

                if ((int)next.size() > (int)maxLength)
                {
                    maxLength = next.size();
                    for (int j = 0; j < next.size(); j++)
                    {
                        now.push_back(next[j]);
                    }
                    ans = now;
                }
            }
        }

        mp[prevGroup][cur] = ans;
        return ans;
    }
};