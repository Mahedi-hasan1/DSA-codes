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

const ll mx =   1e5+5;
vector<vector<int>>v(mx);
bool vis[mx+5];
int val=0, mxt=0;
vector<int>dis1(mx,0), dis2(mx,0), dis(mx,0), inc(mx,0);

int bfs(int st  , vector<int>&dis){
    queue<int>q;
    q.push(st);
    vis[st]=1;
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i=0 ; i<v[tmp].size() ; i++){
            if(vis[v[tmp][i]])continue;
            vis[v[tmp][i]]=1;
            dis[v[tmp][i]] = dis[tmp] +1;
            if(dis[v[tmp][i]]>val){
                mxt= v[tmp][i];
                val = dis[v[tmp][i]];
            }
            q.push(v[tmp][i]);
        }
    }
    return mxt;
}

void clr(vector<int>&diss){
    for(int i=0 ; i<mx ; i++){
        vis[i] = 0;
        diss[i]=0;
        val = 0 ;
        mxt = 0 ;
    }
}


void solve(int tc)
{
    int n;
    cin>>n;
    
    for(int i=0 ; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    int mxa = bfs(1, dis1);
    clr(dis1);
    int mxb = bfs(mxa, dis1);
    clr(dis2);
    bfs(mxb, dis2);  
    //cout<<mxa<< " "<<mxb<<endl;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    int tmp = 1 ;
    for(int i=1; i<=n ; i++){
        dis[i] = max(dis1[i],dis2[i]);
       // cout<<dis[i]<<" "<<dis1[i] <<  " "<<dis2[i]<<endl;
        inc[dis[i]+1]++;
    }
    //cout<<endl;
    for(int i=1; i<=n; i++){
        tmp += inc[i];
        cout<<min(n,tmp)<<" ";
        
    }
    
    cout<<endl;
    
}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}