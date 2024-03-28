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

const ll mx = 1e5+5;
vector<vector<int>>divs(mx+5);

void divcal(){
    for(ll i=1; i<= mx ; i++){
        for(ll j = i; j<=mx ; j+=i){
            divs[j].pb(i);
        }
    }
}

void solve(int tc)
{
    int n,m;
    cin>>n>>m;
    vector<int>ar(n,0);
    for(int i=0 ; i<n; i++)
        cin>>ar[i];
    int cnt =0 ;
    vector<int>v(m+5);
    sort(all(ar));
    int res = INT_MAX;
    int j =0 ;
    for(int i=0 ; i<n; i++){
        for(auto it : divs[ar[i]]){
            if(it>m)continue;
            if(v[it]==0)cnt++;
            v[it]++;
        }
        while(cnt==m){
            res = min(res, (ar[i]-ar[j]));
            for(auto it : divs[ar[j]]){
                if(it>m)continue;
                v[it]--;
                if(v[it] == 0)cnt--;
                
            }
            j++;
        }
    }
    if(res==INT_MAX)res = -1 ;
    cout<<res<<endl;
}
    

int main()
{
    fastio;
    divcal();
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}