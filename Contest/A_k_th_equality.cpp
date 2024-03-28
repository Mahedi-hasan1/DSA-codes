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

ll mn(ll x){
    ll res = 1;
    for(int i= 1; i<x; i++)res*=10;
    return res;
}
ll mx(ll x){
    ll res = 9 ;
    for(int i = 1; i<x; i++){
        res*=10;
        res += 9;
    }
    return res;
}

void solve(int tc)
{
    ll a, b, c, k;
    cin>>a>>b>>c>>k;
    if( c - max(a,b) > 1 || c - max(a,b) < 0 ){
        cout<<-1<<endl;
        return;
    }

    ll st = mn(a), en = mx(a); 
    ll tmp1 = mn(c), tmp2 = mx(c);
    for(ll i = st; i<= en ; i++){
        ll l = tmp1 - i;
        l = max(l, 1ll);
        ll r = tmp2 - i;
        l = max(l, mn(b));
        r = min(r, mx(b));
        if(r<l)continue;
        ll tmp = min(k, r-l+1);
        //cout<<i<<" "<<l<<" "<<r<<endl;
        k-=tmp ;
        if(k==0){
            cout<<i<<" + "<<l+tmp-1<<" = "<<i+l+tmp-1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}