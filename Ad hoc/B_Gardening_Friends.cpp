#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

#define f first
#define s second

#define no cout << "No\n"
#define yes cout << "Yes\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const ll mx = 2e5+5;
vector<vector<ll>>g(mx);
vector<int>dis(mx), dis2(mx);
vector<bool> vis(mx);
ll res = 0 ;

void dfs(int st){
    if(vis[st])return;
    vis[st]=1;
    for(int i=0 ; i<g[st].size() ; i++){
        if(vis[g[st][i]])continue;
        dis[g[st][i]]= dis[st]+1;
        dfs(g[st][i]);
    }

}

void dfs2(int st){
    if(vis[st])return;
    vis[st]=1;
    for(int i=0 ; i<g[st].size() ; i++){
        if(vis[g[st][i]])continue;
        dis2[g[st][i]]= dis2[st]+1;
        dfs2(g[st][i]);
    }

}


void solve(int tc)
{
    ll n, k,c;
    cin>>n>>k>>c;
    ll N= n;
    for(int i=0 ; i<=n; i++){
        g[i].clear();
        vis[i]=0;
        dis[i]=0;
        dis2[i]=0;
    }
    while(n>1){
        ll a, b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
        n--;
    }
    n= N;
    dfs(1);
    ll mx =0,tnode =0;
    for(int i=1 ; i<=n; i++){
        if(dis[i]>mx){
            tnode= i;
            mx = dis[i];
        }
    }
    res = 0 ;
    for(int i=0 ; i<=n; i++){
        vis[i]=0;
        dis2[i]=0;
    }
    dfs2(tnode);
    for(ll i = 1; i<=n ; i++){
        ll tmp =  dis2[i]*k - (dis[i]*c);
        res = max(res, tmp);    
    }
    cout<<res<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}