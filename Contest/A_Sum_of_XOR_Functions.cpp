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
const ll M = 998244353;

void solve(int tc)
{
    int n;
    cin >> n;
    ll ar[n];
    ll csf[n], cse[n], cx[n], sum =0, cs[n];
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
        if (i == 0)
        {
            csf[i] = ar[i];
            cx[i] = ar[i];
            cs[i] = ar[i];
        }
        else
        {
            if (i & 1)
                csf[i] = csf[i - 1];
            else
                csf[i] = csf[i - 1] + ar[i];

            cx[i] = cx[i - 1] ^ ar[i];
            cs[i] = cs[i - 1] + ar[i];
        }
        sum += ar[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            cse[i] = ar[i];
        else
        {
            if ((n - i - 1) & 1)
                cse[i] = cse[i + 1];
            else
                cse[i] = cse[i + 1] + ar[i];
        }
    }
    ll res = sum % M;
    for (int i = 1; i < n; i++)
    {
        ll l = i, r = n - i - 1, tmp=0;
        if (l > r)
            swap(l, r);
        if ((i & 1) ==0)
        {
            tmp = cx[r];
            if(l){
                tmp ^= cx[l-1];
            }
        }
        cout<<l<<" "<<r<<" ";
        if(l)tmp += csf[l-1];
        if(r+1<n) tmp += cse[r+1];
        tmp %= M;
        tmp = (tmp*(i+1))%M;
        res = (res + tmp) % M;
        cout<<res<<endl;
    }
    cout<<res<<endl;
}

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}