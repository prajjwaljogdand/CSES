#include <bits/stdc++.h>
using namespace std;

#define ll long long

/**
 * refference https://codeforces.com/blog/entry/102085
*/

int main()
{

    ll n, m , k;
    cin >> n >> m >> k;
    vector<vector<pair<ll, ll>>> adj(n + 1);
    vector<ll> count(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    for (ll i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    pq.push({0, 1});

    while (count[n] < k)
    {
        auto it = pq.top();
        pq.pop();
        ll node = it.second;
        ll dis = it.first;
        // if I already taken k routes to reach this node
        // dont explore that node
        if(count[node] == k) continue;
        count[node] +=1;

        if(node == n){
            cout << dis << " ";
        }
        for (auto it : adj[node])
        {
            ll child = it.second;
            ll ew = it.first;
            pq.push({ dis + ew , child});
        }
    }

    return 0;
}