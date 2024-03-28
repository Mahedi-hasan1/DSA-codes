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
vector<vector<int>>gr(mx);
vector<bool>vis(mx);
vector<ll>cor(mx);
bool ans = 1;

void dfs(int st, map<ll, ll> &dis){
    if(vis[st])return;
    vis[st]=1;

    for(int i=0 ; i<gr[st].size() ; i++){
        int ch = gr[st][i];
        if(vis[ch]){
            if(cor[ch] != cor[st] + dis[st*mx+ch]){
                ans = 0 ;
            }
        }
        else cor[ch]= cor[st]+ dis[st*mx+ch];
        dfs(ch, dis);

    }
}

void solve(int tc)
{
    int n, m;
    cin>>n>>m;
    map<ll, ll> dis;
    for(int i=0 ;i<=n; i++){
        vis[i]=0;
        cor[i] = 0 ;
        gr[i].clear();
    }
    ans = 1;
    vector<pair<ll, pair<ll,ll>>>inp;
    for(int i=0 ;i<m; i++){
        ll a, b, d;
        cin>>a>>b>>d;
        inp.pb({a, {b,d}});
        gr[a].pb(b);
        gr[b].pb(a);
        if(dis[a*mx+b]){
            if(dis[a*mx+b]!=d)ans = 0 ;
        }
        dis[a*mx+b]=d;
        dis[b*mx+a]=-d;
    }
    
    for(int i= 1; i<=n ; i++){
        dfs(i,dis);
    }
    n = inp.size();
    for(int i=0 ;i<n; i++){
        if(dis[inp[i].f*mx+ inp[i].s.f] != inp[i].s.s)ans= 0;
    }
    if(ans)YES;
    else NO;


}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}