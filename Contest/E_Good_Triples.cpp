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
    map<int,int>cnt;
    for(int i=0 ; i<10; i++){
        for(int j=0 ; j<10 ; j++){
            for(int k=0; k<10 ; k++){
                cnt[i+j+k]++;
            }
        }
    }
    ll rs = 1;
    for(int i=0 ; i<s.size() ; i++){
        rs *= cnt[s[i]-'0'];
    }
    cout<<rs<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}