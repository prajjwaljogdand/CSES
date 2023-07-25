#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

/**
 * Floyd - Marshal algorithm
 * Time complexity : O(V3)
*/

int main()
{
    IOS;

    ll n, m, q;
    cin >> n >> m >> q;
    ll M = 1000000000000;

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, M));
    for (int i = 0; i < m; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][a] = 0;
        dist[b][b] = 0;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }

    for (int k = 1; k < n + 1; k++)
    {
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    while (q--)
    {
        ll i, j;
        cin >> i >> j;
        dist[i][j] == M ? cout << -1 << endl : cout << dist[i][j] << endl;
    }
    return 0;
}