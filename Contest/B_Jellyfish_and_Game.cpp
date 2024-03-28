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
    ll n,m,k, sum = 0;
    cin>>n>>m>>k;
    vector<ll>a(n),b(m);
    for(int i=0 ; i<n; i++)
        cin>>a[i];
    for(int i=0 ; i<m; i++)
        cin>>b[i];
    
    sort(all(a));
    sort(all(b));

    ll mx = max(a[0], b[m-1]);
    ll mn = min(a[0], b[m-1]);
    a[0] = mx;
    b[m-1] = mn;
    if(k&1){
        for(int i=0 ; i<n; i++)sum+= a[i];
        cout<<sum<<endl;
        return;
    }
    sort(all(a));
    sort(all(b));
    mx = max(a[n-1], b[0]);
    mn = min(a[n-1], b[0]);
    a[n-1] = mn;
    b[0] = mx;
    for(int i=0 ; i<n; i++)
        sum+= a[i];
    cout<<sum<<endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}