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
    int n, m;
    cin>>n>>m;
    int ar[n][m];
    for(int i=0 ; i<n; i++){
        for(int j =0 ;j<m; j++)
            cin>>ar[i][j];
    }
    map<string, bool>mark;
    for(int i=0 ; i<n; i++){
        vector<pair<int,int>>v(m);
        for(int j=0; j<m; j++){
            v[j]= {ar[i][j],j};
        }
        sort(all(v));
        string s ="";
        for(int j=0 ; j<m; j++){
            char c = v[j].s + '0';
            s+= c;
            mark[s]=1;
        }
    }
    for(int i=0 ; i<n; i++){
        string s ="";
        int ans = 0;
        for(int j=0; j<m; j++){
            char c = ar[i][j]-1+'0';
            s+= c;
            if(mark[s])ans = j+1;
        }
        cout<<ans<<" ";
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