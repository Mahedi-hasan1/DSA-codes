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
    cin >> s;
    int n = s.size();
    sort(all(s));
    set<char> st;
    map<char, int> cnt;
    for (int i = 0; i < n; i++){
        cnt[s[i]]++;
        st.insert(s[i]);
    }
    string b = "", f = "";
    while (!st.empty())
    {
        char tmp = *st.begin();
        st.erase(tmp);
        int k = cnt[tmp];
        for (int i = 0; i < k / 2; i++)
        {
            f += tmp;
            b += tmp;
        }
        if (k % 2)
        {
            if (st.size() == 1)
            {
                char tmp2 = *st.begin();
                st.erase(tmp2);
                int kk = cnt[tmp2];
                for (int i = 0; i < (kk+1)/2; i++)
                    f += tmp2;
                for(int i=0 ; i<kk/2; i++)
                    b+= tmp2;
                b+= tmp;
                
            }
            else
            {
                b += tmp;
                while (!st.empty())
                {
                    char tmp2 = *st.begin();
                    st.erase(tmp2);
                    int kk = cnt[tmp2];
                    for (int i = 0; i < kk; i++)
                        f += tmp2;
                }
            }
            break;
        }
    }
    reverse(all(b));
    cout<<f+b<<endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}