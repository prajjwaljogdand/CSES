#include <bits/stdc++.h>
using namespace std;

#define ll long long


void dfs(ll i, vector<vector<ll>> & adj, vector<bool> &vis){

    if(vis[i]) return;
    vis[i] = true;
    for(auto child : adj[i]){
        if(!vis[child]){
            dfs(child,adj,vis);
        }
    }

}

int main()
{

    ll n , m;
    cin>>n>>m;
    vector<vector<ll>> adj(n+1);
    vector<bool> vis(n+1, false);

    for(ll i = 0 ; i < m; i++){
       ll a ,b;
       cin>>a>>b;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }

    vis[0] = true;
    ll count = 0;
    vector<ll> heads;
    for(ll i = 0 ; i <= n ; i++){
        if(!vis[i]){
            dfs(i,adj,vis);
            heads.push_back(i);
            count++;
        }
    }

    cout<<heads.size()-1<<endl;

    for(ll i = 0 ; i < heads.size()-1; i++){
        cout<<heads[i]<<" "<<heads[i+1]<<endl;
    }

    return 0;
}