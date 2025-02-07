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

bool pos(vector<ll>&v, ll m , ll k, ll i, ll n){
    ll tmp = m, mov =k;

    for( ; i<n; i++){
        if(v[i]>=tmp)return true;
        if(i==n-1 || (tmp-v[i])>mov) return false;
        
        mov -= (tmp-v[i]);
        tmp--;
    }
    return true;

}

void solve(int tc)
{
    ll n, k;
    cin>>n>>k;
    vector<ll>v(n);
    for(int i=0 ; i<n; i++){
        cin>>v[i];
    }

    ll ans = v[0] ;

    for(int i=0 ;i<n; i++){
        ll l = v[i]-1 , r = v[i] + k ;

        while(r - l > 1){
           ll m = (l+r)/2; 
           if(pos(v, m,k, i, n)){
              l = m;
              ans = max(m, ans);
           }
           else r = m;
        }

    }  
    cout<<ans<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}