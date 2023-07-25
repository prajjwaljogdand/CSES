#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll shortLen = INT_MAX;

/**
 * this is example of bipartite graph
*/

bool dfs(vector<vector<ll>> & adj , vector<int> & color , int col , int node){

    color[node] = col;
    for(auto child : adj[node]){
        if(color[child] == -1){
            int newCol = col == 1 ? 2 : 1;
             if(dfs(adj,color,newCol,child) == false){
                return false;
             }
        }else if(color[child] == col){
            return false;
        }
    }
   return true;
}

int main()
{

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    vector<int> color(n+1 , -1);

    for (ll i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++){
          if(color[i] == -1){
            if(dfs(adj,color,1,i) == false ) {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
          }
    }

     for(int i = 1 ; i <= n ; i++){
        cout<<color[i]<<" ";
     }


    return 0;
}