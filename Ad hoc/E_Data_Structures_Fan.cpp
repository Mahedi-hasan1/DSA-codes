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
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0 ; i<n; i++)cin>>v[i];
    string s;
    cin>>s;
    vector<ll>fxor(n,0), bxor(n,0);
    ll zr = 0 , on = 0 ;
    for(int i=0 ; i<n; i++){
        if(i)fxor[i] = fxor[i-1]^v[i];
        else fxor[i] = v[i];
        if(s[i]=='0')zr^=v[i];
        else on^= v[i];
    }
    for(int i=n-1; i>=0 ; i--){
        if(i==n-1)bxor[i]=v[i];
        else bxor[i] = v[i]^bxor[i+1];
    }
    int q; cin>>q;
    while(q--){
        int a,b,c;
        cin>>a;
        if(a==2){
            cin>>b;
            if(b==0)cout<<zr<<" ";
            else cout<<on<<" ";
        }   
        else {
            cin>>b>>c;
            b--;
            c--;
            ll tmp = 0 ;
            if(b-1>=0)tmp = fxor[b-1];
            if(c+1<n)tmp^=bxor[c+1];
            tmp ^= fxor[n-1];
            zr ^= tmp;
            on ^= tmp;
        }
       
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