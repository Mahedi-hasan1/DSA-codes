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
    string s;
    cin>>s;
    int n = s.size();
    vector<int>fc(n,0), bc(n,0);
    for(int i=0 ; i<n; i++){
        if(i==0 && s[i]=='1')fc[i] = 1;
        if(i!=0){
            fc[i] = fc[i-1] ;
            if(s[i]=='1')fc[i]++;
        }
    }
    ll  ans = 1e18, cost1 = 1e12, cost2 = 1e12+1;
    for(int i=0 ; i<=n; i++){
        ll bad1=0 , bad2 = 0 ;
        if(i){
            bad1 = fc[i-1];
        }
        if(i<=n-1){
            ll len = n-1-i+1;
            bad2 = len - fc[n-1];
            if(i)bad2 += fc[i-1];
        }
        ans = min(ans, (bad1+bad2)*cost2);
        if( i<n-1 && s[i]=='1' && s[i+1] =='0'){
            bad2 -= 1;
            ans = min(ans, cost1 + (bad1+bad2)*cost2);
        }
    }
    cout<<ans<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}