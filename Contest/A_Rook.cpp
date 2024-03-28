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
    for(int i=1; i<=8 ; i++){
        if(i== (s[1]-'0'))continue;
        cout<<s[0]<<i<<endl;
    }
    for(int i=0 ; i<8 ; i++){
        if(s[0]== 'a'+i)continue;
        char c = 'a' + i;
        cout<<c<<s[1]<<endl;
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