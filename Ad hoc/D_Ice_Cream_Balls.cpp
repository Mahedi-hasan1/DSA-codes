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

bool pos(ll m, ll n){
    ll res  = (m*(m-1))/2;
    if(res>=n)return 1;
    return 0;
}

void solve(int tc)
{
    ll n;
    cin>>n;
    ll l = 1, r = 2648956422;
    while(r-l>1){
        ll m = (r+l)/2;
        if(pos(m, n)){
            r = m;
        }
        else l = m;
    }
    ll tmp = r*(r-1);
    tmp/=2;

    if(tmp>n){
        tmp = (r-1)*(r-2);
        tmp/=2;
        r = r-1 + (n-tmp);
    }
    cout<<r<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}