class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool compFunc(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }

    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int, int>> aux;
        for (int i = 0; i < n; i++)
        {
            aux.push_back(make_pair(start[i], end[i]));
        }

        sort(aux.begin(), aux.end(), compFunc);
        int track = -1;
        int cnt = 0;
        for (const auto& x : aux)
        {
            if (x.first > track)
            {
                cnt++;
                track = x.second;
            }
        }
        return cnt;
    }
};