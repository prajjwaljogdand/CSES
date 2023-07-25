#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * Bellman-Ford Algorithm
 * Time complexity : O(VE)
*/

int main()
{

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(m);
    vector<ll> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<int> vis(n + 1, 0);

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[i].push_back(a);
        adj[i].push_back(b);
        adj[i].push_back(c);
    }

    dist[1] = 0;

    for (ll i = 0; i < n ; i++)
    {
        for (auto it : adj)
        {
            ll u = it[0];
            ll v = it[1];
            ll wt = it[2];
            // cout << u << v << wt << endl;
            if (dist[u] != INT_MIN)
            {
                if (dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                }
            }
        }
    }

    int C = -1;

    for (auto it : adj)
    {
        ll u = it[0];
        ll v = it[1];
        ll wt = it[2];
        // cout << u << v << wt << endl;

        if (dist[u] + wt < dist[v])
        {
            C = v;
            break;
        }
    }


    if (C != -1)
    {
        for (int i = 0; i < n; i++)
        {
            C = parent[C];
            //  cout<<parent[i]<<" ";
        }
        vector<int> cycle;
        for (int v = C;; v = parent[v])
        {
            cycle.push_back(v);
            if (v == C && cycle.size() > 1)
                break;
        }

        reverse(cycle.begin(), cycle.end());
        cout << "YES" <<endl;
        for (int v : cycle)
            cout << v << ' ';
    }
    else
    {
        cout << "NO";
    }

    return 0;
}