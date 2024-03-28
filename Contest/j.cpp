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

bool in(ll x, ll y, ll r)
{
    return (r * r > (x * x + y * y));
}
bool out(ll x, ll y, ll r)
{
    return (r * r < (x * x + y * y));
}

void solve(int tc)
{
    ll r;
    //cin >> r;
    r= tc;
    ll ans = 4, y = r, cnt = 0, x=1;
    for (; x < y; x++)
    {
        if (in(x, y, r))
        {
            continue;
        }
        else if (out(x, y, r))
        {
            while (out(x, y - 1, r))
                y--;
            if(!in(x,y-1,r)){
                cnt++;
                y--;

            }
        }
        else
        {
            cnt++;
        }
    }
    if(x==y && !in(x,y,r) && !out(x,y,r))ans+=4;
    ans+= (8*cnt);
    cout<<r<<" "<<ans<<endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}