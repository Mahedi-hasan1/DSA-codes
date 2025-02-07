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


void solve(int tc)
{
    long long a,b,c, v;
    cin>>a>>b>>c>>v;
    
    ll res =0 ;
    for(ll i =1; i<=a; i++){
        if(v%i)continue;
        ll tmp = v/i;
        for(ll j = 1; j<=b ; j++){
            if(tmp%j)continue;
            ll x = tmp/j;
            if(x<=c){
                res = max(res, (a-i+1)*(b-j+1)*(c-x+1));
            }
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