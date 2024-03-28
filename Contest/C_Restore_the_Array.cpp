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
    int ar[n];
    for(int i =0 ; i<n-1; i++) 
        cin>>ar[i];
    vector<int>v;
    v.pb(ar[0]);
    for(int i=1; i<n-1 ; i++){
        if(ar[i]>= ar[i-1]){
            v.pb(ar[i-1]);
        }
        else v.pb(ar[i]);
    }

    v.pb(ar[n-2]);
    for(int i=0 ; i<n; i++){
        cout<<v[i]<<" ";
    }
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