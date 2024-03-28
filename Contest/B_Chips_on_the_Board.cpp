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
    int n;
    cin>>n;
    vector<ll>v(n), v2(n);
    ll sum1 =0, sum2 =0 , mn1 = INT_MAX, mn2 = INT_MAX;
    for(int i=0 ; i<n; i++) {
        cin>>v[i];
        sum1 += v[i];
        mn1 = min(mn1, v[i]);
    }
    for(int i =0 ;i<n; i++){
        cin>>v2[i];
        sum2 += v2[i];
        mn2 = min(mn2, v2[i]);
    }
    cout<<min(mn1*n + sum2, mn2*n + sum1)<<endl;
    
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}