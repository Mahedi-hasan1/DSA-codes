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
    string s[n];
    for(int i=0 ; i<n; i++){
        cin>>s[i];
    }
    int st[n+1][n+1], en[n+1][n+1];
    memset(st, 0 , sizeof st);
    memset(en, 0 , sizeof en);

    ll res = 0 ;
    
    for(int i= 0; i<n; i++){
        for(int j=0 ; j<n; j++){
            if(i==0)break;
            if(st[i-1][j]){
                st[i][max(0,j-1)] += st[i-1][j];
            }
            if(en[i-1][j]){
                en[i][min(n, j+1)] += en[i-1][j];
            }
        }

        ll tmp = 0 ;
        for(int j = 0 ; j<n; j++){
            tmp += st[i][j];
            tmp -= en[i][j];
            int tt = tmp&1;
            int val = s[i][j]-'0';
            if((val^tt)){
                res++;
                st[i][j]++;
                en[i+1][min(n,j+2)]++;
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