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

const ll mod = 1e9+7;

void solve(int tc)
{
    ll n,k;
    cin>>n>>k;
    ll ar[n], jr = 0, br = 0;
    for(int i=0 ;i<n; i++){
        cin>>ar[i];
        if(ar[i]%2==0)jr++;
        else br ++;
    }
    if(k==1){
        if(abs(jr-br)> 1)cout<<0<<endl;
        else{
            ll res = 1 ;
            for(ll i = 1; i<=jr; i++)res = (res*i)%mod;

            for(ll i=1; i<=br; i++) res = (res*i)%mod;
            if(jr == br) res = (res*2)%mod;
            cout<<res<<endl;
        }
    }
    else {
        if(jr != n && br !=n){
            cout<<0<<endl;
        }
        else {
            ll res = 1;
            for(ll i = 1; i<=n ; i++) res = (res*i)%mod;
            cout<<res<<endl;
        }
    }
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}