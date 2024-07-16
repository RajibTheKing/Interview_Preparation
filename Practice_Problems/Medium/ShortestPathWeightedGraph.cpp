class compareGreater
{
public:
    const bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

class Solution {
  public:
    int dist[100001];
    int prev[100001];
    vector<pair<int,int>> adj[100001];

    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        for (int i = 1; i <= n; i++)
        {
            dist[i] = INT_MAX;
            prev[i] = -1;
        }

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back(make_pair(v, w));
            adj[v].push_back(make_pair(u, w));
        }

        solve_Dijkstra(1);

        vector<int> ans;

        if (dist[n] == INT_MAX)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(dist[n]);
            vector<int> path = getPath(n);
            copy(path.begin(), path.end(), back_inserter(ans));
        }
        return ans;
    }

    vector<int> getPath(int t)
    {
        if (t == 1)
        {
            vector<int> path;
            path.push_back(t);
            return path;
        }
        vector<int> path = getPath(prev[t]);
        path.push_back(t);
        return path;
    }
    void solve_Dijkstra(int source)
    {
        priority_queue <pair<int,int>, vector<pair<int,int>>, compareGreater> PQ; 
        dist[source] = 0;
        PQ.push(make_pair(source, dist[source]));

        while (!PQ.empty())
        {
            pair<int, int> currentNode = PQ.top();
            PQ.pop();

            int u = currentNode.first;

            for (const auto& next : adj[u])
            {
                int v = next.first;
                int w = next.second;

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    prev[v] = u;
                    PQ.push(make_pair(v, dist[v]));
                }
            }
        }
    }
};