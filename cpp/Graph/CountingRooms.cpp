#include <bits/stdc++.h>
using namespace std;

#define ll long long


void dfs(int i , int j , vector<vector<char>> & arr, int count, vector<vector<bool>> &vis , int n , int m){

    if( i < 0 || j < 0 || i >= n || j >= m )  return;
    if(arr[i][j] == '#') return;
    if(vis[i][j]) return;
    vis[i][j] = true;
    arr[i][j] = '#';

    dfs(i+1,j,arr,count,vis,n,m);
    dfs(i-1,j,arr,count,vis,n,m);
    dfs(i,j+1,arr,count,vis,n,m);
    dfs(i,j-1,arr,count,vis,n,m);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n , m;
    cin>>n>>m;
    vector<vector<char>> arr;
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    for(int i = 0 ; i < n ; i++){
        vector<char> tmp;
        for(int j = 0 ; j < m ; j++){
            char t;cin>>t;
            tmp.push_back(t);
        }
        arr.push_back(tmp);
    }

    int count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(!vis[i][j] && arr[i][j] == '.'){
                dfs(i,j,arr,count,vis,n,m);
                count++;

            }
        }
    }

    cout<<count<<endl;

    return 0;
}