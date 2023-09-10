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

ll segsum(ll l, ll r){
    return ((r-l)*(r+l+1))/2;
}

void solve(int tc)
{
    ll n, x, y;
    cin>>n>>x>>y;
    ll lc = (x*y)/(__gcd(x,y));
    ll tx = n/x, ty = n/y, tlc= n/lc;
    tx-= tlc;
    ty-= tlc;

    ll sum = segsum(n-tx, n);
    sum -= segsum(1, ty);

    cout<<sum-1<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}