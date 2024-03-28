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
    int n,m;
    cin>>n>>m;
    string s, p;
    cin>>s>>p;
    string res ="";
    res += s[0];
    for(int i=1 ; i<n ; i++){
        if(s[i]==s[i-1]){
            res += p;
        }
        res+= s[i];
    }
    bool f = 1;
    //cout<<res<<" ";
    for(int i=1 ; i<res.size(); i++){
        if(res[i] == res[i-1]){
            f=0;
            break;
        }
    }
    if(f)yes;
    else no;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}