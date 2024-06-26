class Compare
{
public:
    bool operator()(pair<char, int> left, pair<char, int> right)
    {
        return left.second < right.second;
    }
};

class Solution 
{
public:
    string reorganizeString(string s)
    {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        int cnt[26];
        for (int i = 0; i < s.size(); i++)
        {
            int now = s[i] - 'a';
            cnt[now]++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] != 0)
            {
                char c = i+'a';
                pq.push(make_pair(c, cnt[i]));
            }
        }

        string ans = "";
        char prev = '1';

        while (!pq.empty())
        {
            pair<char, int> now = pq.top();
            pq.pop();

            if (now.first != prev)
            {
                ans+=now.first;
                prev = now.first;
                now.second--;
                if (now.second > 0)
                    pq.push(now);
            }
            else if (now.first == prev && !pq.empty())
            {
                pair<char, int> next = pq.top();
                pq.pop();
                ans += next.first;
                prev = next.first;
                next.second--;
                if (next.second > 0)
                    pq.push(next);
                pq.push(now);
            }
            else
            {
                return "";
            }
        }
        return ans;
    }
};