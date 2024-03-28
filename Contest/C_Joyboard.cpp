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
    ll n, m, k;
    cin>>n>>m>>k;
    ll tmp = 1;
    if(k==1)cout<<tmp<<endl;
    if(m>=n)tmp += (m/n)+ n-1;
    else tmp += m;
    if(k==2)cout<<tmp-1<<endl;
    tmp = (m+1)-tmp;
    if(k==3)cout<<tmp<<endl;
    if(k>3)cout<<0<<endl;
}
    

int main()
{
    //fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}