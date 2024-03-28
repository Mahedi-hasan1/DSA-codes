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
    cin >> n;
    ll ar[n];
    for(int i=0 ; i<n; i++)cin>>ar[i];
    ll left[n], right[n];
    ll pos=0;
    left[1]=ar[0]-1;
    for(int i=2 ; i<n-1 ; i++){
        if(ar[i-1]-1>ar[pos]-(i-pos)){
            pos = i-1;
        }
        left[i] = ar[pos]-(i-pos);
    }
    pos = n-1;
    right[n-2] = ar[n-1]-1;
    for(int i= n-3; i>=1; i--){
        if(ar[i+1]-1 > ar[pos] - (pos-i) ){
            pos = i+1;
        }
        right[i] = ar[pos] - (pos-i);
    } 
    ll mx =-INT_MAX ;
    for(int i=1 ; i<n-1; i++){
        mx = max(mx, left[i] + right[i] + ar[i]);
    }
    cout<<mx<<endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}