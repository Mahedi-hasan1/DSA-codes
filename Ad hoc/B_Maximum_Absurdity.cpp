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
const ll mx = 2e5+5;
int ar[mx];

void solve(int tc)
{
    int n, k;
    cin>>n>>k;
    for(int i=0 ; i<n;  i++){
        cin>>ar[i];
    }
    vector<ll>signs(n,0);
    ll tmp =0 ;
    for(int i=0 ; i<k ; i++){
        tmp+= ar[i];
    }
    signs[0]= tmp;
    for(int i=k ; i<n; i++){
        tmp-=ar[i-k];
        tmp+= ar[i];
        signs[i-k+1]=tmp;

    }
    vector<pair<ll,ll>>indSigns(n);
    ll mx =0, pos = n-1 ;
    for(int i = n-k; i>=0 ; i--){
        if(signs[i]>=mx){
            pos=i;
            mx = signs[i];
        }
        indSigns.pb({mx, pos}); 
    }
    reverse(all(indSigns));
    
    pair<ll,ll>res = {0,0};
    mx = 0 ;
    for(int i=0 ; i<=n-k ; i++){
        if (signs[i] + indSigns[i+k].f > mx){
            res = {i, indSigns[i+k].s};
            mx = signs[i] + indSigns[i+k].f;
        }
    }
    cout<<res.f+1<< " "<< res.s+1<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
   // cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}