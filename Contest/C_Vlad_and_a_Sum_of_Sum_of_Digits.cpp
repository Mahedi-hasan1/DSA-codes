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

ll const mx = 2e5+1;

ll ans[mx];

ll sum(ll x){
    ll res =0 ;
    while(x>0){
        res += x%10;
        x/=10;
    }
    return res;
}

void cal(){
    for(int i=1; i<mx; i++)ans[i] = ans[i-1]+ sum(i);
}

void solve(int tc)
{
    int n;
    cin>>n;
    cal();
    cout<<ans[n]<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}