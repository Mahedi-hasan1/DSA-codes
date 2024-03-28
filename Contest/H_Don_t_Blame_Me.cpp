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
const ll mod = 1e9 + 7;
void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    ll mem[n][69];
    memset(mem, 0, sizeof mem);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 63; j++)
        {
            if (ar[i] == j)
                mem[i][j] = (mem[i][j]+1)%mod;
            if (i)
            {
                if (mem[i - 1][j])
                    mem[i][j] = (mem[i][j] + mem[i - 1][j])%mod;
                if (mem[i - 1][j])
                    mem[i][j & ar[i]] = (mem[i][j & ar[i]] + mem[i - 1][j]) % mod;
            }
        }
    }
    
    int res = 0;
    for (int i = 0; i <= 63; i++)
    {
        int tmp = __builtin_popcount(i);
        if (tmp == k)
        {
            res = (res + mem[n-1][i])%mod;
        }
    }
    cout << res << endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}