#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

#define ff first
#define ss second

#define No cout << "No\n"
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"


void solve(int tc)
{
    string s;
    cin>>s;
    int n = s.size();
    stack<pair<char,int>>st1, st2;
    for(int i=0 ; i<n; i++){
        if(s[i]=='B'){
            if(!st2.empty())st2.pop();
        }
        else if (s[i]=='b' ){
            if(!st1.empty())st1.pop();
        }
        else if (s[i]>='a' && s[i] <= 'z'){
            st1.push({s[i], i});
        }
         else if(s[i]>='A' && s[i]<='Z') st2.push({s[i], i});
    }
    vector<pair<int,char>>ans;
    while(!st1.empty()){
        auto it = st1.top();
        ans.pb({it.ss, it.ff});
        st1.pop();
    }
    while(!st2.empty()){
        auto it = st2.top();
        ans.pb({it.ss,it.ff});
        st2.pop();
    }
    sort(all(ans));
    for(int i=0 ; i<ans.size() ; i++)cout<<ans[i].ss;
    cout<<endl;
}


int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
