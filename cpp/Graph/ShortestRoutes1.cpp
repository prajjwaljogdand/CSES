#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{

    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<ll> dist(n + 1, INT64_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        ll node = it.second;
        ll dis = it.first;
        if(dist[node] < dis)
        continue;
        for (auto it : adj[node])
        {
            ll child = it.second;
            ll ew = it.first;
            if (dis + ew < dist[child])
            {
                dist[child] = dis + ew;
                pq.push({ dis + ew , child});
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}