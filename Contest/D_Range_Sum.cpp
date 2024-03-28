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
    ll n;
    cin>>n;
    vector<ll>ans;
    if((n&1) == 0){
        for(int i=n/2  ; i<n; i++){
            ans.pb(i);
        }
        for(int i=n+1; i<= n+ n/2; i++)ans.pb(i);
    }
    else{
        ll k= n*4;
        ans.pb(k);
        ll k2 = k;
        for(int i= 1; i< n/2; i++){
            k-=2;
            k2+=2;
            ans.pb(k);
            ans.pb(k2);
        }
        ans.pb(k-3);
        ans.pb(k2+3);
    }
    for(int i=0 ;i<n; i++){
        cout<<ans[i]<<" ";
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