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

const ll M = 1e9+7;

ll inv(ll a , ll b){
    if(b==0)return 1;
    ll x;
    if(b&1){
        x = inv(a, b-1);
        return (x*a)%M;
    }
    x = inv(a, b/2);
    return (x*x)%M;
    
}

void solve(int tc)
{
    int n, m;
    cin>>n>>m;
    map<int,int>cnt;
    vector<int>ar;
    for(int i=0,a ; i<n; i++){
        cin>>a;
        cnt[a]++;
        if(cnt[a]==1)ar.pb(a);
    }
    n = ar.size();
    ll tmp = 1, res =0 , st = 0;
    sort(all(ar));
    for(int i=0 ; i<n; i++){
        tmp = (tmp*cnt[ar[i]])%M;
        if(i && ar[i]-ar[i-1]>1){
            tmp = cnt[ar[i]];
            st = i;
        }
        if(i-st+1 == m){
            res = (res+tmp)%M;
            tmp = (tmp * inv(cnt[ar[st]], M-2))%M;
            st++;
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