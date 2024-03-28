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
    map<ll,ll>lp;
    int n;
    cin>>n;
    vector<ll>c(n), ans(n,0);
    for(int i=0 ; i<n; i++){
        cin>>c[i];
        lp[c[i]]=i;
    }
    ll k;
    cin>>k;
    
    ll st = 0 , cur = INT_MAX, pos = -1;
    for(auto it : lp){
        if(it.ss<pos)
            continue;
        ll dif = it.ff - st;
        ll val = min(cur, k/dif);
        ans[it.ss] = val;
        k -= val*dif;
        st = it.ff;
        cur = val;
        pos = it.ss;
    }
    ll tmp =0 ;
    for(int i =n- 1; i>=0 ; i--){
        tmp = max(tmp, ans[i]);
        ans[i]=tmp;
    }
    for(int i=0 ; i<n; i++)cout<<ans[i]<<" ";
    cout<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}