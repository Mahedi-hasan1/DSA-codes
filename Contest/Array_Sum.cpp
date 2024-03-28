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
    ll n, k;
    cin >> n >> k;
    ll sum = n / 2 + n;
    int ar[n];

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
            ar[i] = 1;
        else
            ar[i] = 2;
    }

    k -= (n + n / 2);
    if(k<0 || k%2){
         cout<<-1<<endl;
         return;
    }

    for (int i = 0; i < n; i++)
    {
        ll x = 1e5 - 2;
        ll tmp = min(k, x);
        k -= tmp;
        ar[i] += tmp;
    }
    if(k)cout<<-1<<endl;
    else {
        for(int i=0 ; i<n; i++)cout<<ar[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}