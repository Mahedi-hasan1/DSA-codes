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
    ll n,ans =0;
    cin>>n;
    ll ar[n];
    for(int i=0 ; i<n; i++)cin>>ar[i];
    vector<int>ons(22,0);
    for(int i=0 ; i<n; i++){
        ll tmp = ar[i];
        int j = 0 ;
        while(tmp>0){
            if(tmp&1){
                ons[j]++;
            }
            tmp/=2;
            j++;
        }
    }
    for(int i=0 ; i<n; i++){
        ll val = 0,tmp = 1 ;
        for(int j=0 ; j<22 ;j++){
            if(ons[j]){
                val+= tmp;
                ons[j]--;
            }
            tmp*=2;
        }
        
        ans += (val*val);
    }
    cout<<ans<<endl;
    
}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}