#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

ll sum(string s)
{
    
    ll n = s.size()-1, sum = 0;
    set<char>st;
    //show(n);
    for(ll i=n; i>=1; i--)
    {
       // show("bipul");
        ll sgn = 1, tem = 0;
        if(s[i] == 'A') tem = 1;
        if(s[i] == 'B') tem = 10;
        if(s[i] == 'C') tem = 100;
        if(s[i] == 'D') tem = 1000;
        if(s[i] == 'E') tem = 10000;

        //cout << "Tem ind : "<< tem << " "<< i << endl;
        for(char ch = s[i] + 1; ch <= 'E'; ch++)
        {
            if(st.count(ch) && st.size())
                sgn = -1;
        }

        st.insert(s[i]);
        tem *= sgn;
        sum += tem;
    }

    st.clear();
    return sum;
    
}

void solve(int tc)
{

    string s;
    cin >> s;

    map<char, int>left, right;
    s = '#' + s;
    ll n = s.size() - 1;
    ll ans = sum(s);
    //show(ans);

    for(int i=1; i<=n; i++){
        if(left[s[i]] == 0)
            left[s[i]] = i;
    }

    for(int i=n; i>=1; i--)
    {
        if(right[s[i]] == 0)
            right[s[i]] = i;
    }

    for(int i=1; i<=n; i++)
    {
        if(left[s[i]] == i)
        {
            for(char ch = s[i]; ch <= 'E'; ch++)
            {
                string tem = s;
                tem[i] = ch;
                ll newSum = sum(tem);
                ans = max(ans, newSum);
            }
        }
    }

    for(int i=n; i>=1; i--)
    {
        if(right[s[i]] == i)
        {
            for(char ch = s[i]; ch>='A'; ch--)
            {
                string tem = s;
                tem[i] = ch;
                ll newSum = sum(tem);
                ans = max(ans, newSum);
            }
        }
    }

    cout << ans << endl;
}
    

int main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}