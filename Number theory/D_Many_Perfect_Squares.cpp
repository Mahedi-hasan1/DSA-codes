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
ll pp , qq;
bool isint(ll d, ll tmp){
    tmp /= d;
    ll tmp2 = tmp - d;
    ll tmp3 = tmp + d;
    pp = tmp2/2;
    pp*=pp;
    qq = tmp3/2;
    qq*=qq;
    return (tmp2%2==0)&(tmp3%2==0);
}

bool issq(ll x){
    ll tmp = sqrt(x);
    return (tmp*tmp == x);
}

void solve(int tc)
{
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0 ; i<n; i++)
        cin>>ar[i];
    sort(ar, ar+n);
    vector<ll>posx;
    for(int i=0 ; i<n; i++){
        for(int j=i+1; j<n; j++){
            ll tmp = ar[j]-ar[i];
            vector<ll>divs;
            for(ll k= 1; k*k <= tmp ; k++){
                if(tmp  == (tmp/k)*k){
                    divs.pb(k);
                    if(k != tmp/k) divs.pb(tmp/k);
                }
            }
            for(ll k = 0 ; k<divs.size() ; k++){
                bool f = isint(divs[k], tmp);
                if(f){
                    if(pp-ar[i]>=0)posx.pb(pp-ar[i]);
                    if(qq-ar[j]>=0)posx.pb(qq-ar[j]);
                }
            }
        }
    }
    ll res = 1 ;
    for(int i=0 ; i<posx.size(); i++){
        ll tmp = 0 ;
        for(int j = 0 ; j<n; j++){
            tmp += issq(ar[j]+ posx[i]);
        }
        res = max(res, tmp);
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