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
const ll M = 1e9+7;
ll n, m;

ll mnmod(ll a, ll b){
    ll res = (a%M - b%M);
    if(res<0)res+= M;
    return res;
}
ll inv(ll a, ll b){
    if(b==0)return 1;
    if(b%2==0){
        ll x = inv(a, b/2);
        return (x*x)%M;
    }
    return (inv(a, b-1)* a)%M;
}

ll cal(ll st, ll en, ll inc){
    if(st<en)return 0 ;
    ll val = n%st;
    ll len = st-en+1;
    len %= M;
    ll res = ((val*len)%M  + (inc * (len%M * (len-1)%M)%M)%M * inv(2, M-2))%M;
    //res = val*len + (inc *(n*(n+1))/2);
    return res;
}

void solve(int tc)
{
    cin>>n>>m;
    ll res = 0 ;
    if(m>n){
        res = (n%M * mnmod(m,n))%M;
    }
    m = min(m, n-1);
    ll sqn = sqrt(n);
    if(m>sqn){
        ll tmp = n/m;
        ll st = n/tmp;
        ll en = (n/(tmp+1))+1;
        en = max(en, sqn+1);
        res = (res + cal(st, en, tmp)) % M;
        res = mnmod(res , cal(st, m+1, tmp)) % M;
        for(ll i = tmp+1; ; i++){
            st = n/i;
            en = n/(i+1)+1;
            if(en<=sqn){
                en = sqn+1;
                res = (res + cal(st, en, i))%M;
                break;
            }
            else res = (res + cal(st, en, i))%M;
        }
    }
    for(ll i=1; i<= min(m, sqn) ; i++){
        res = (res + (n%i) )%M;
    }
    cout<<res<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}