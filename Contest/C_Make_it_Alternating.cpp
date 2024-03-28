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

const ll mx = 2e5+5, mod = 998244353;
ll fac[mx];

void solve(int tc)
{
    string s;
    cin>>s;
    ll res = 1 , n = s.size();
    ll cnt = 1 , ops = 0;
    for(int i=1 ; i<n; i++){
        if(s[i]==s[i-1])cnt++;
        else {
            if(cnt ==1)continue;
            res *= cnt;
            res %= mod;
            ops += cnt-1;
            cnt = 1;
            
        }
        
    }
    if(cnt != 1){
        res *= cnt;
        res %= mod;
        ops += cnt-1;
        cnt = 1;
        
    }
    
    res = res * fac[ops];
    res %= mod;

    cout<<ops<<" "<<res<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    fac[0]=1;
    for(int i=1; i<mx; i++){
        fac[i] = (fac[i-1]*i) % mod;
    }
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}