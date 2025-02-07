#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

#define ff first
#define ss second

#define No cout << "No\n"
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"


void solve(int tc)
{
    int n, x;
    cin>>n>>x;
    vector<int>v(n), dp(n);
    
    for(int i=0 ; i<n; i++)cin>>v[i];
    for(int i=0 ; i<n; i++)dp[i]=v[i];
    for(int i=0 ; i<n; i++){
        if(i-x-1>0){
            dp[i]+= dp[i-x-1];
        }
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout<<dp[n-1]<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    //in >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}