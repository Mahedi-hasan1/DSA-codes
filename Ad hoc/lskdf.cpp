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
    char c;
    cin>>c;
    int n = sizeof(s);
    int ar[n], br[n];
    memset(ar, 0 , sizeof ar);
    memset(br, 0 , sizeof br);
    for(int i=0 ; i<n; i++){
        if(i)ar[i]=ar[i-1];
        if(s[i]==c)ar[i]++;
    }
    for(int i=n-1 ; i>=0 ; i--){
        if(i<n-1)br[i] = br[i+1];
        if(s[i]==c)br[i]++;
    }
    int cnt = 0 ;
    for(int i=1 ; i<n-1; i++){
        if(ar[i-1] == br[i+1])cnt++;
    }
    cout<<cnt<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}