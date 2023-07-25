#include <bits/stdc++.h>
using namespace std;

#define ll long long


vector<int> ans;
void dfs(ll i, vector<vector<pair<int,int>>> & adj, vector<bool> &vis ,int count, int n){

    if(i == n) {
        ans.push_back(count);
        return;
    }
    if(vis[i]) return;
    vis[i] = true;
    for(auto child : adj[i]){
        if(!vis[child.first]){
            cout<<child.first<<endl;
            dfs(child.first,adj,vis,child.second + count,n);
        }
    }
    vis[i] = false;

}

int main()
{

    ll n , m , k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool> vis(n+1, false);

    for(ll i = 0 ; i < m; i++){
       ll a ,b ,c;
       cin>>a>>b>>c;
       adj[a].push_back({b,c});
    }

    vis[0] = true;
    ll count = 0;
    vector<ll> heads;

    dfs(1,adj,vis,count,n);

    sort(ans.begin(),ans.end());

    for(ll i = 0 ; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}