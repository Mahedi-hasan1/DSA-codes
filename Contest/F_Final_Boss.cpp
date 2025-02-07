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

bool possbl(ll x, vector<ll>&at, vector<ll>&cd, ll h){
    ll val = h , n = at.size();
    if(x == 0)return 0;
    for(ll i=0 ;i<n ;i++){
        val -= ((1+ (x-1)/cd[i])*at[i]);
        if(val<=0)return true;
    }
    
    return false;
}

void solve(int tc)
{
    ll h, n;
    cin>>h>>n;
    vector<ll>at(n), cd(n);
    for(int i=0 ; i<n; i++){
        cin>>at[i];
    }
    for(int i=0 ; i<n; i++){
        cin>>cd[i];
    }

    ll l = -1 , r = 1e12, res = 1e12 ;
    while(r - l > 1){
        ll m = (l+r)/2;
        if(possbl(m,at, cd,h )){
            r = m;
            res = min(m, res);
        }
        else l = m;
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