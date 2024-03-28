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

ll valu(char c){
    if(c == 'A') return 1;
    else if (c == 'B') return 10 ;
    else if (c == 'C') return 100;
    else if (c == 'D') return 1000;
    else  return 10000;
}
ll value(ll c, ll cnt){

    if(c == 0) c = 1;
    else if (c == 1) c = 10 ;
    else if (c == 2) c = 100;
    else if (c == 3) c = 1000;
    else  c = 10000;
    return (c*cnt);

}
ll comp(ll c, ll mx){

    if(c == 0) c = 1;
    else if (c == 1) c = 10 ;
    else if (c == 2) c = 100;
    else if (c == 3) c = 1000;
    else  c = 10000;
    if(c<mx) return ((-1) *c);
    else return c;

}

void solve(int tc)
{
    string s;
    cin>>s;
    int n = s.size();
    vector<vector<int>>v(n, vector<int>(5,0));
    for(int i=0 ; i<n; i++){
        for(int j=0 ; j<5; j++){
            if(i)v[i][j] = v[i-1][j];
        }
        v[i][s[i]-'A']++;
    }
    
    ll tmp =0 , mx = 0;
    vector<ll>lsum(n ,0),lmx (n,0);
    for(int i= n-1 ; i>=0 ; i--){
        if(i==n-1){
            tmp += valu (s[i]);
        }
        else {
            if(valu(s[i])<mx) tmp -= valu(s[i]);
            else tmp += valu(s[i]);
        }
        mx = max(mx, valu(s[i]));
        lsum[i] = tmp;
        lmx[i] = mx;
    }
    ll res = 0 ;
    for(int i=0 ; i<n; i++){
        int mxn = 0 ;
        if(i<n-1){
            mxn = to_string(lmx[i+1]).size() - 1; 
        }
        for(int j= max(0, mxn) ; j<5; j++){
            ll ans = 0 ;
            for(int k = 0 ; k<5; k++){
                if(i){
                    if(k>= j) ans += value(k , v[i-1][k]);
                    else ans -= value(k, v[i-1][k]);
                }
            }
            ans += valu('A'+j);
            if(i!= n-1)ans += lsum[i+1];
            cout<<i<<" "<<j<<" "<<ans<<endl;
            res = max(res, ans);
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