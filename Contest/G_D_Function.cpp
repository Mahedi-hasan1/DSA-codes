#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

#define ff first
#define ss second

#define No cout << "No\n"
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
const ll mod = 1e9+7;
ll powr(ll a, ll b){
    if(b==0)return 1;
    if(b%2==0){
        ll x = powr(a, b/2);
        return (x*x)%mod;
    }
    return (a*powr(a, b-1))%mod;
}

ll sum ( ll l , ll r ){
    if(l==0){
        ll x = (r*(r+1))/2;
        return x % mod;
    }
    l--;
    ll x = (r*r) + r - (l*l) - l;
    x/=2;
    return x % mod;
}

void solve(int tc)
{
    ll l, r, k;
    cin>>l>>r>>k;
    if(k>9){
        cout<<0<<endl;
        return;
    }
    ll tmp = 9/k;
    
    tmp ++ ;
    ll res = powr(tmp, r) - 1;
    res %= mod;
    if(res<0)res += mod;
    //cout<<res<<" ";
    if(l>0){
        res -= (powr(tmp,l)-1);
        res %= mod;
        if(res<0)res += mod;
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