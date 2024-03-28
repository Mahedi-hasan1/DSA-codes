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
    int n;
    cin>>n;
    string s[n];
    for(int i=0 ; i<n; i++)
        cin>>s[i];

    ll cc[n], rr[n];
    ll res = 0 ;
    for(int i=0 ; i<n; i++){
        int cnt =0, cnt2=0;
        for(int j=0 ;j<n; j++){
            if(s[j][i] == 'o')cnt++;
            if(s[i][j] == 'o')cnt2++;
        }
        cc[i]=cnt;
        rr[i]=cnt2;
    }
    for(int i =0 ; i<n; i++){
        for(int j=0 ; j<n; j++){
            if(rr[i]>=2 && cc[j]>=2)res += (rr[i]-1)*(cc[j]-1);
        }
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