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

const ll mx = 1e6+5;
vector<vector<ll>>divs(mx+1);


void solve(int tc)
{
    int n;
    cin>>n;
    int ar[n];
    map<int,int>cnt;
    for(int i=0 ; i<n ; i++){
        cin>>ar[i];
        cnt[ar[i]]++;

    }
    int mxx = 0 ;
    for(int i=0 ; i<mx ;i++){
        mxx = max(mxx, (int)divs[i].size());
    }
    cout<<mxx<<endl;
    // for(int i=0 ; i<n; i++){
    //     int tmp = ar[i];
    //     set<ll>tdivs;
    //     for(int j=0 ; j<divs[tmp].size() ; j++){

    //     }

    // }
}
    

int main()
{
    fastio;
    int t = 1;
    for(int i=1; i*i<=mx;  i++){
        for(int j = i ; j<=mx ; j+= i){
            divs[j].pb(i);
        }
    }
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}