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
    ll n;
    cin>>n;
    ll ar[n];
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
    }
    ll rem = 0 , tak = 0 , til = n-1;
    for(int i=n-1 ; i>=0; i--){
        if(ar[i]>= 0){
            rem += ar[i];
            if(i%2==0) {
                tak += rem;
                rem = 0;
                til = i-1;
            }
        }
    }
    ll mx = -INT_MAX;
    for(int i=0 ; i<= til ; i++){
        if(ar[i]>=0){
            tak += rem ;
            tak -= ar[i] ;
            tak += max(0ll, ar[i]+mx);
            break;
        }
        mx = max(mx, ar[i]);
    }

    cout<<tak<<endl;


}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}