class Solution {
public:
    static bool compareFunc(vector<int>& a, vector<int>& b)
    {
            if (a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
    }

    int maxEvents(vector<vector<int>>& events)
    {
        sort(events.begin(), events.end(), compareFunc);
        set<int> days;
        int totalEvents = 0;
        for (int i = 1; i <= 100000; i++)
        {
            days.insert(i);
        }

        for (const auto& event : events)
        {
            int s = event[0];
            int e = event[1];
            auto it = days.lower_bound(s);
            if (it == days.end() || *it > e )
            {
                continue;
            }
            else
            {
                totalEvents++;
                days.erase(it);
            }
        }
        return totalEvents;
    }
};