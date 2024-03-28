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

bool pos(vector<int>&v, ll m, ll k){
    ll n = v.size(), sum = 0 ;;
    if(v[0] != 1)return 0 ;
    for(int i=1 ; i<n; i++){
        if(v[i]>m)continue;
        ll con = 1 + (m-v[i])/(i+1);
        m -= min(k,con);
        sum += min(k, con);
    }
    sum += k;
    return (sum>=m);
}   

void solve(int tc)
{
    ll n, k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0 ; i<n; i++)cin>>v[i];

    ll l = 0 , r = 1e15;
    ll res = 1e18, res2 = 0;
    while(r - l > 1){
        ll m  = (r+l)/2;
        if(pos(v, m, k)){
            l  = m;
        }
        else  {
            r = m; 
            res = min(res, m);
        }
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