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

bool pos(string &s)
{
    int n = s.size();
    bool f = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
            return 0;
    }
    return 1;
}

void solve(int tc)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool f = 1;
    vector<int> ans;
    if (n % 2)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < 300; i++)
    {
        string res = "";
        for (int j = 0; j < n / 2; j++)
        {
            if (s[j] == s[n - j - 1])
            {
                f=0;
                if (s[j] == '1')
                {
                    ans.pb(j);
                    for (int k = 0; k < j; k++)
                        res += s[k];
                    res += "01";
                    for (int k = j; k < n; k++)
                        res += s[k];
                }
                else
                {
                    ans.pb(n - j);
                    for (int k = 0; k <= n - j - 1; k++)
                    {
                        res += s[k];
                    }
                    res += "01";
                    for (int k = n - j ; k < n; k++)
                        res += s[k];
                }
                s = res;
                //cout<<s<<endl;
                n = s.size();
                if (pos(s))
                {
                    f = 1;
                }
                break;
            }
        }
        if(f)break;
    }
    if (f)
    {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    else
        cout << -1 << endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}