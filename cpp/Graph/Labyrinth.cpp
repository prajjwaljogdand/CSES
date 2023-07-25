#include <bits/stdc++.h>
using namespace std;

#define ll long long

stack<char> st;
vector<stack<char>> ansList;

void dfs(int i, int j, vector<vector<char>> &arr, int count, vector<vector<bool>> &vis, int n, int m)
{

    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (arr[i][j] == '#')
        return;
    if (arr[i][j] == 'B')
    {
        ansList.push_back(st);
        // cout<<"pushed"<<endl;
        st.pop();
        return;
    };
    if (vis[i][j])
        return;
    vis[i][j] = true;
    // cout<<i<<j<<endl;
    if (i + 1 <= n && (arr[i + 1][j] == '.' || arr[i + 1][j] == 'B') && !vis[i+1][j])
    {
        //  cout<<'D'<<endl;
        st.push('D');
        dfs(i + 1, j, arr, count, vis, n, m);

    }
    if (i - 1 >= 0 && (arr[i - 1][j] == '.' || arr[i - 1][j] == 'B') && !vis[i-1][j])
    {
        //   cout<<'U'<<endl;
        st.push('U');
        dfs(i - 1, j, arr, count, vis, n, m);

    }
    if (j + 1 <= m && (arr[i][j + 1] == '.' || arr[i][j + 1] == 'B') && !vis[i][j+1])
    {
        //  cout<<'R'<<endl;
        st.push('R');
        dfs(i, j + 1, arr, count, vis, n, m);

    }
    if (j - 1 >= 0 && (arr[i][j - 1] == '.' || arr[i][j - 1] == 'B') && !vis[i][j-1])
    {
        // cout<<'L'<<endl;
        st.push('L');
        dfs(i, j - 1, arr, count, vis, n, m);

    }
    st.pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;
    vector<vector<char>> arr;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        vector<char> tmp;
        for (int j = 0; j < m; j++)
        {
            char t;
            cin >> t;
            tmp.push_back(t);
        }
        arr.push_back(tmp);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && arr[i][j] == 'A')
            {
                dfs(i, j, arr, count, vis, n, m);
                count++;
            }
        }
    }

    long unsigned int ans = INT_MAX;
    int index  = 0;
    for (long unsigned int i = 0; i < ansList.size() ; i++)
    {
        if( ans >  ansList[i].size() ){
             ans = ansList[i].size();
             index = i;
        }

    }

    stack<char> ansVec;
    while(!ansList[index].empty()){
       ansVec.push(ansList[index].top());
       ansList[index].pop();
    }
    cout<<ans<<endl;
    while(!ansVec.empty()){
        cout<< ansVec.top();
        ansVec.pop();
    }
    cout<<endl;

    return 0;
}


/**
 *
LDDRRRUURRD

LDDRR RRRU
pushed
R
35
R
36
U
pushed
 *
 *
 *
*/