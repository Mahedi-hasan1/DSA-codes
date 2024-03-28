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

bool pos(ll m, vector<pair<ll,ll>> &v){
    int n = v.size();
    ll mx= 0, mn =0;

    for(int i=0; i<n;i++){
        mn -= m;
        mx += m;
        if(v[i].ff >mx  || v[i].ss< mn) return 0;
        mn = max(mn, v[i].ff);
        mx = min(mx, v[i].ss);
    }
    return 1;
}

void solve(int tc)
{
    int n;
    cin>>n;
    
    vector<pair<ll,ll>>v(n);
    for(int i =0 ; i<n; i++){
        cin>>v[i].ff>>v[i].ss;
    }

    ll l = -1 , r = 1e10 , ans = 1e10; 
    while(r-l>1){
        ll m = (r+l)/2;
        if(pos(m, v)){
            r = m;
            ans = min(ans,m);
        }
        else {
            l = m;
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