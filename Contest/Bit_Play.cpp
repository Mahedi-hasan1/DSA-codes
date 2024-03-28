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

const ll mod  = 1e9+7;
void solve(int tc)
{
    int n;
    cin>>n;
    string s; 
    cin>>s;
    ll res = 1 ;
    for(int i=2 ; i<n; i+=2){
        int a = s[i-2]-'0', b = s[i-1]-'0', c = s[i]-'0'; 
        //cout<<a<<" "<<b<<" "<<c<<endl;
        ll tmp = 0;
        if((a&b)==c)tmp++;
        if((a|b)==c)tmp++;
        if((a^b)==c)tmp++;
        res  = (res*tmp)%mod;
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