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

ll cll(ll a, ll b){
    ll res = a/b;
    if((a/b)*b != a)res++;
    return res;
}

void solve(int tc)
{
    ll n;
    cin>>n;
    ll tmp = n, en = n-1;
    vector<pair<ll,ll>>ops;

    while(tmp>1){
        ll tmp2 = sqrt(tmp);
        tmp2 = max(2ll, tmp2);
        for(ll i = tmp2+1; i<=en; i++){
            ops.pb({i,n});
        }
        en = tmp2;
        tmp = cll(tmp, tmp2);
        ops.pb({n,tmp2});
    }
    cout<<ops.size()<<endl;
    for(int i=0 ; i<ops.size() ; i++)
        cout<<ops[i].f<<" "<<ops[i].s<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}