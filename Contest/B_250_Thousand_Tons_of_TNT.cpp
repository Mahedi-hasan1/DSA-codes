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

ll pcs(vector<int>&ar, ll x){
    ll n = ar.size();

    ll mn = 1e17, mx = 0 , tmp=0;
    for(int i=0 ; i<n; i++){
        tmp += ar[i];
        if((i+1)% x == 0){
            mn = min(mn, tmp);
            mx = max(mx, tmp);
            tmp = 0;
        }
    }
    //cout<<mx-mn<<endl;
    return mx - mn;
    
}

void solve(int tc)
{
    int n;
    cin>>n;
    vector<int>ar(n,0);
    for(int i =0 ; i<n; i++){
        cin>>ar[i];
    }
    ll val = n, res = 0;
    for(int i=1; i*i<=n ; i++){
        if(n%i==0){
            res = max(pcs(ar, i), res);
            res = max(pcs(ar, n/i), res);
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