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

ll inv(ll a, ll b){
    if(b==0)return 1;
    if(b&1) return (inv(a, b-1) * a)%M;
    ll tmp = inv(a, b/2);
    return (tmp*tmp)%M;
}

void solve(int tc)
{
    ll n,k;
    cin>>n>>k;
    for(int i=0 ; i<n-1; i++){
        int a, b;
        cin>>a>>b;
    }
    if(k&1)cout<<1<<endl;
    else if(k==2){
        ll a= 2, b = n-1;
        ll res = 0 , dnt=0;
        for( ; a<=n; a++){
            res += (a*b);
            res %= M;
            dnt += b;
            dnt %= M;
            b--;
        }
        res = (res * inv(dnt, M-2))%M;
        cout<<res<<endl;
    }
    else{
        ll a = n, b = n-2, c = 1;
        ll res = 0 , dnt = 0 ;
        for( ; b>=1; b--){
            ll tmp = b;
            tmp *= c;
            tmp%=M;
            dnt += tmp;
            dnt %= M;
            tmp *= a;
            tmp %= M;

            res += tmp;
            res %= M;
            c++;a--;
        }
        res = (res * inv(dnt, M-2))%M;
        cout<<res<<endl;
    }

}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}