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

ll pos(vector<ll>&ar, ll m, ll x){
    ll n = ar.size();
    ll sum = 0 ;
    for(int i=0 ; i<n; i++){
        sum += max(0ll, m - ar[i]);
    }
    if(sum<=x)return 1;
    return 0;
}

void solve(int tc)
{
    ll n, x;
    cin>>n>>x;
    vector<ll>ar(n,0);
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
    }
    sort(all(ar));

    ll l = 1, r = 1e13;
    while(r-l>1){
        ll m = (r+l)/2;
        if(pos(ar, m, x)){
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