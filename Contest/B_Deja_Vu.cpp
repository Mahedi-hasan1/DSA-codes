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

ll pwr(ll a, ll b){
    if(b==0) return 1;
    if(b%2)
     return a * pwr(a, b-1);
    ll tmp = pwr(a, b/2);
    return tmp *tmp;
}

void solve(int tc)
{
    int n,q;
    cin>>n>>q;
    ll ar[n], qr[n];
    vector<vector<pair<ll,ll>>>v(35);
    for(int i = 0; i<n; i++){
        cin>>ar[i];
        int j = 0, tmp = 2; 
        while(ar[i] % tmp ==0){
            j++;
            tmp *=2;
        }
        v[j].pb({i,ar[i]});
    }

    for(int i=0,a ; i<q; i++){
        cin>>qr[i];
        for(int j = qr[i] ; j<v.size(); j++){
            for(int k =0 ; k<v[j].size() ; k++){
                v[qr[i]-1].pb({v[j][k].f , v[j][k].s+ pwr(2, qr[i]-1)});
            }
            v[j].clear();
        }
    }
    
    vector<pair<ll,ll>>res;
    for(int i=0 ; i<v.size(); i++){
        for(int j =0; j<v[i].size() ; j++)
            res.pb({v[i][j].f, v[i][j].s});
    }
    sort(all(res));
    for(int i=0; i<res.size() ; i++)cout<<res[i].s<<" ";
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