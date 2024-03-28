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


bool pos(vector<ll>&v, ll k , ll m){
    ll n = v.size(), cnt = k ;
    while(k-- && m>0){
        int xx = upper_bound(v.begin(), v.end() , m)-v.begin();
        m-= xx;
    }
    if(m>0)return 0;
    else return 1;
}

void solve(int tc)
{
    int n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for(int i=0 ; i<n; i++)
        cin>>v[i];

    ll r = 1e12, l = 0 , res = 1e12;
    while(r-l>1){
        ll m = (r+l)/2;
        if(pos(v,k,m)){
            l = m;
        }
        else {
            r = m;
            res = min(res,r);
        }

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