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

ll pcs(int i, int j  , int n){
    ll x = min({i+1, j+1, n-i, n-j});
    return x;
}

void solve(int tc)
{
    string s[10];
    for(int i=0 ; i<10 ; i++)cin>>s[i];
    ll res = 0 ;
    for(int i=0 ; i<10 ; i++){
        for(int j =0 ; j<10 ; j++){
            if(s[i][j]== 'X'){
                res += pcs(i, j, 10);
            }
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