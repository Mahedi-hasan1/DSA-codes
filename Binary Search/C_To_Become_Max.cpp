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

bool pos(vector<ll>&v, ll pos , ll m, ll k){
    ll tmp = m, sum =0, n = v.size();

    for(int i = pos ; i<n; i++){
        if(i==n-1){
            if(v[i]<tmp)sum += 1e15;
            continue;
        }
        if(v[i]>=tmp)break;
        sum += max(0ll, tmp-v[i]);
        tmp -= 1;
    }
    return (sum<=k) ;
}

void solve(int tc)
{
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for(int i=0 ; i<n; i++)cin>>v[i];

    ll mx = 0 ;
    for(int i=0 ; i<n; i++){

        ll l = v[i] -1 , r = v[i] + k +5;

        while( r - l > 1){
            ll m = (r+l)/2;

            if(pos(v, i , m, k)){
                l = m;
                mx = max(mx,m);
            }
            else r = m;
        }
    }

    cout<<mx<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}