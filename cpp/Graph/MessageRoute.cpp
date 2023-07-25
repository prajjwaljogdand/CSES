#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll shortLen = INT_MAX;

int main()
{

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<int> dist(n + 1, 1e9);
    vector<int> parents(n + 1);
    for (int i = 0; i < n + 1; i++)
        parents[i] = i;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist[1] = 0;
    pq.push({1, 1});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.first;
        int dis = it.second;
        for (auto it : adj[node])
        {
            if (dis + 1 < dist[it])
            {
                dist[it] = dis + 1;
                pq.push({it, dis + 1});
                parents[it] = node;
            }
        }
    }


    if (dist[n] == 1e9)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    cout << dist[n] << endl;

    vector<int> path;
    int node = n;

    while (parents[node] != node)
    {
        path.push_back(node);
        node = parents[node];
    }

    path.push_back(1);
    cout << endl;
    reverse(path.begin(), path.end());

    for (auto i : path)
    {
        cout << i << " ";
    }

    return 0;
}