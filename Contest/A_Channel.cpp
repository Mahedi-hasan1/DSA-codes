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
    int n, k, q, tmp =0;
    cin>>n>>k>>q;
    string s;
    cin>>s;
    bool f =0 , f1 =0 ;
    if(k>=n)f=1;
    tmp=k;
    for(int i=0 ; i<q; i++){
        if(s[i]=='+')k++;
        else k--;
        if(k>=n)f=1;
        if(s[i]=='+')tmp++;
    }
    if(tmp>=n)f1=1;
    if(f)YES;
    else if(f1)cout<<"MAYBE"<<endl;
    else NO;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}