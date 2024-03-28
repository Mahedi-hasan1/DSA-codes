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
    vector<int>v;
    bool vis[n+1];
    for(int i=0 ; i<=n; i++)vis[i]=0;
    for(int i=1; i<=n; i++){
        int j = i;
        while((vis[j]==0) && (j<= n)){
            v.pb(j);
            vis[j]=1;
            j*=2;
        }
    }
    for(int i=0; i<v.size() ; i++)
        cout<<v[i]<<" ";
    cout<<endl;
    v.clear();
}
    

int main()
{
    //fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}