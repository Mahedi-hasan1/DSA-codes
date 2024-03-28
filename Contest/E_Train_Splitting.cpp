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


void solve(int tc)
{
    int n, e;
    cin>>n>>e;
    vector<vector<int>>v(n+1);
    vector<int>edg(6000,2);
    vector<pair<int,int>>vp;
    for(int i =0 ; i<e ; i++){
        int a, b;
        cin>>a>>b;
        if(a>b)swap(a,b);
        v[a].pb(b);
        v[b].pb(a);
        vp.pb({a,b});
    }
    if(e < (n*(n-1))/2){
        for(int i=1; i<=n; i++){
            if(v[i].size() && v[i].size() != n-1){
                for(int j=0 ; j<v[i].size() ; j++){
                    int x = i , y = v[i][j];
                    if(x>y)swap(x,y);
                    edg[x*100+y]=1;
                }
                break;
            }
        }
        cout<<2<<endl;
    }
    else{
        for(int j=2; j<n; j++)edg[1*100+j]=1;
        edg[100+n]=3;
        cout<<3<<endl;
    }
    for(int i=0 ;i<vp.size() ; i++){
        cout<<edg[vp[i].f*100 + vp[i].s]<<" ";
    }
    cout<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}