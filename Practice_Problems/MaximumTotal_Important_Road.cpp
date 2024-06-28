class Importance
{
public:
    int country;
    int frequency;
    Importance(int c, int f)
    {
        country = c;
        frequency = f;
    }
};

class Solution {
public:
    static bool compareFunc(Importance a, Importance b)
    {
        return a.frequency > b.frequency;
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            mp[i] = 0;
        }
        for(int i=0; i<roads.size(); i++)
        {
            int a = roads[i][0];
            int b = roads[i][1];
            mp[a]++;
            mp[b]++;
        }

        vector<Importance> imp;
        for(const auto& m : mp)
        {
            imp.push_back(Importance(m.first, m.second));
        }

        sort(imp.begin(), imp.end(), compareFunc);

        map<int, int> tracker;

        for(int i=n, j=0; i>=1; i--, j++)
        {
            tracker[imp[j].country] = i;
        }

        long long sum = 0;
        for(int i=0; i<roads.size(); i++)
        {
            sum += tracker[roads[i][0]] + tracker[roads[i][1]];
        }

        return sum;

    }
};