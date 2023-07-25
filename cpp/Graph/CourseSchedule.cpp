#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool cycle(ll s, vector<vector<ll>> & adj, vector<int> &v1){
    v1[s]=1;
    for (auto i: adj[s]){
        if (!v1[i]){
            if (cycle(i,adj,v1)) return 1;
        }
        else if (v1[i]==1) return 1;
    }
    v1[s] = 2;
    return 0;
}


void dfs(ll i, vector<vector<ll>> & adj, vector<bool> &vis, stack<int> &v){
    if(vis[i]) return;
    vis[i] = true;
    for(auto child : adj[i]){
        if(!vis[child]){
            dfs(child,adj,vis,v);
        }
    }
    v.push(i);
}

int main()
{

    ll n , m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<bool> vis(n+1, false);
    stack<int> v;
    vector<int> v1(n+1,0);

    for(ll i = 0 ; i < m; i++){
       ll a ,b;
       cin>>a>>b;
       adj[a].push_back(b);
    }

    vis[0] = true;
    ll count = 0;
    vector<ll> heads;
    for(ll i = 0 ; i <= n ; i++){
        if (!v1[i] && cycle(i,adj,v1)) {cout<<"IMPOSSIBLE";return 0 ;}
        if(!vis[i]){
            dfs(i,adj,vis,v);
        }
    }

    while(!v.empty()){
        cout << v.top() << " ";
        v.pop();
    }


    return 0;
}