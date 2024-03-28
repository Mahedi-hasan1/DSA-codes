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

typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
const ll mx = 2e5+5;
map<ll, map<ll, pair<ll, ll>>> val;
vector<vector<ll>> g(mx + 1);
vector<pair<ll, ll>> res(mx + 1);
vector<int> mark(mx + 1, 0);
vector<int> vis(mx + 1, 0);
void dfs(ll st)
{
    if (vis[st])return;
    vis[st]=1;
    //cout<<st<<endl;
    for(int i=0 ; i<g[st].size() ; i++){
        if(vis[g[st][i]])continue;
        int p = st, c = g[st][i];
        res[c] = {res[p].f+val[p][c].f ,res[p].s+val[p][c].s}; 
        mark[c]=1;
        dfs(c);
    }
}

void solve(ll tc)
{
    ll n, m;
    cin >> n >> m;

    while (m--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        val[a][b] = {c, d};
        val[b][a] = {-c, -d};
        g[a].pb(b);
        g[b].pb(a);
    }
    mark[1]=1;
    res[1]={0,0};
    dfs(1);
    for(int i=1; i<=n; i++){
        if(mark[i])cout<<res[i].f<<" "<<res[i].s<<endl;
        else cout<<"undecidable"<<endl;
    }
}

int main()
{
    fastio;
    ll t = 1;
   // cin >> t;
    for (ll i = 1; i <= t; i++)
        solve(i);
}