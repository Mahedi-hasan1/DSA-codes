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
const int N = 200000+5;
vector<int> graph[N];
bool vis[N];
vector<vector<int>> cycles;



void dfs_cycle(int u, int p, int color[], int par[], int& cyclenumber)
{
    if (color[u] == 2) {
        return;
    }
    if (color[u] == 1) {
        vector<int> v;
        cyclenumber++;
        int cur = p;
          v.push_back(cur);
        while (cur != u) {
            cur = par[cur];
              v.push_back(cur);
        }
          cycles.push_back(v);
        return;
    }
    par[u] = p;
    color[u] = 1;
    for (int v : graph[u]) {
        if (v == par[u]) {
            continue;
        }
        dfs_cycle(v, u, color, par, cyclenumber);
    }
    color[u] = 2;
}

void bfs(int st, vector<int>&dis){
    queue<int>q;
    q.push(st);
    vis[st]=1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        
        for(int i=0 ; i< graph[tmp].size() ; i++){
            if(vis[graph[tmp][i]])continue;
            dis[graph[tmp][i]]= dis[tmp]+1;
            vis[graph[tmp][i]]=1;
            q.push(graph[tmp][i]);
        }
    }
}

void solve(int tc)
{


    int n, a, b;
    cin>>n>>a>>b;
    for(int i=0 ; i<=n; i++)graph[i].clear();
    cycles.clear();

    for(int i=0 ; i<n; i++){
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int color[N];
    int par[N];
    vector<int>disa(n+1), disb(n+1);
    for(int i=0 ; i<=n; i++){
        color[i]=0;
        par[i]=0;
        disa[i]=INT_MAX;
        disb[i]=INT_MAX;
        vis[i]=0;
    }
    
   
    int cyclenumber = 0;
    dfs_cycle(1, 0, color, par, cyclenumber);
    vector<int>cv;
    for (int i = 0; i < cyclenumber; i++) {
        for (int x : cycles[i]){
            cv.pb(x);
            //cout<<x<<" ";
        }
        //cout<<endl;
    }
    disa[a]=0;
    bfs(a,  disa);
    disb[b]=0;
    for(int i=0; i<=n; i++)vis[i]=0;
    bfs(b, disb);
    //cout<<cv.size()<<endl;
    for(int i=0 ; i<cv.size() ; i++){
        //cout<<cv[i]<<" "<<disa[cv[i]]<<" "<<disb[cv[i]]<<endl;
        if(disa[cv[i]]> disb[cv[i]]){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);

    return EXIT_SUCCESS;
}