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
const ll mx = 1e5+4;
vector<ll>primes;
void solve(int tc)
{
    ll q; cin>>q;
    while(q--){
        ll x;
        cin>>x;
        ll n = primes.size();
        map<ll,ll>cnt;
        for(int i=0 ;i<n && primes[i]<=x; i++){
            while((x/primes[i])*primes[i] == x){
                x/= primes[i];
                cnt[primes[i]]++;
            }
        }
        if(x>1)cnt[x]++;
        ll res = 1;
        for(auto it : cnt)res *= (it.s+1);
        cout<<res-1<<endl;
    }
}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    vector<bool>mark(mx+1,1);
    for(ll i=2; i<=mx; i++){
        if(mark[i])primes.pb(i);
        else continue;
        for(ll j=i*i; j<=mx ; j+=i)
            mark[j]=0;
    }
    for (int i = 1; i <= t; i++)
        solve(i);
}