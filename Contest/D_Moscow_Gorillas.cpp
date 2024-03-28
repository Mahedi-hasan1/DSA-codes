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


void solve(int tc)
{
    int n;
    cin>>n;
    int ar[n] , br[n];
    map<int,int>pos,pos2;
    for(int i=0; i<n; i++){
        cin>>ar[i];
        pos[ar[i]]=i;
    }
    for(int j=0; j<n ; j++){
        cin>>br[j];
        pos2[br[j]]=j;
    }
    ll res = 1;
    ll tmp = min(pos[1], pos2[1]);
    res += (tmp*(tmp+1))/2;
    tmp = max(pos[1], pos2[1])-1 - tmp;
    if(tmp>0) res += (tmp*(tmp+1))/2;
    tmp = n - 1 - max(pos[1], pos2[1]);
    res += (tmp*(tmp+1))/2;
    ll l = min(pos[1], pos2[1]), r = max(pos[1], pos2[1]);
    for(int i=2 ; i<=n; i++){
        ll val1 = min(pos[i], pos2[i]);
        ll val2 = max(pos[i], pos2[i]);
        //cout<<i<<"  "<<val1<<" "<<val2<<"   "<<l<<" "<<r<<endl;
        if(val1 <l && val2 < l){
            res += (l-max(val1, val2))*(n-r);
        }
        else if(val1> r && val2>r){
            res += (min(val1, val2)-r)*(l+1);
        }
        else res += max(0ll, l-val1) * max(0ll , val2-r);

        l = min({val1, l, val2});
        r = max({r, val2, val1});
    }
    cout<<res<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}