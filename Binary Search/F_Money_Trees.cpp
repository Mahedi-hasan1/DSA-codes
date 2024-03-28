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

bool pos(vector<vector<ll>>&v , ll m ,ll k){
    ll n = v.size();
    ll f = 0 ;
    for(int i = 0 ; i<n; i++){
        if(v[i].size()<m)continue;
        ll sum =0 ;
        ll sz = (ll)v[i].size();
        for(int j = 0 ; j<m; j++)sum+= v[i][j];
        if(sum<=k )return 1;
        for(int j = m; j<sz; j++){
            sum-= v[i][j-m];
            sum += v[i][j];
            if(sum<=k)return 1;
        }
    }
    return 0 ;
}

void solve(int tc)
{
    ll n, k;
    cin>>n>>k;
    vector<ll>fr(n),ar(n);
    for(int i=0 ; i<n; i++)cin>>fr[i];
    for(int i=0 ; i<n; i++)cin>>ar[i]; 
    vector<vector<ll>>v;
    
    for(int i=0 ; i<n; i++){
        vector<ll>tmp;
        tmp.clear();
        tmp.pb(fr[i]);
        while(i+1<n && (ar[i]%ar[i+1]==0)){
            tmp.pb(fr[i+1]);
            i++;
        }
        //i--;
        if(tmp.size())v.pb(tmp);
    }
    ll l = 0 , r = n+1;
    while(r-l>1){
        ll m = (r+l)/2;
        if(pos(v, m, k)){
            l = m;
        }
        else r = m;
    }
    cout<<l<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}