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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    k--;
    int l = k , r = k;
    if(k+1<=(n+1)/2){
        for(int i=k-1; i>=0 ; i--){
            if(s[i] != s[n-1-i]){
                l = i;
            }
        }
        for(int i= k+1; i< n/2 ; i++){
            if(s[i] != s[n-1-i])r = i;
        }
    }
    else{
         for(int i=k-1; i>=(n+1)/2 ; i--){
            if(s[i] != s[n-1-i]){
                l = i;
            }
        }
        for(int i= k+1; i<n ; i++){
            if(s[i] != s[n-1-i])r = i;
        }
    }
    ll len = min((k-l)*2 + r-k, (r-k)*2 + k-l);
    
    for(int i=0 ; i<n/2  ; i++){

        ll tmp = abs(s[i]- s[n-1-i]);
        len += min(tmp, 26 - tmp);
    }
    cout<<len<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}