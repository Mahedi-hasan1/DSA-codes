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
    int n, m;
    cin>>n>>m;
    string s[n];
    for(int i=0 ; i<n; i++)cin>>s[i];
    int x1, y1, x2,y2;
    bool f = 0;
    for(int i=0 ; i<n; i++){
        for(int j =0; j<m; j++){
            if(f==0 && s[i][j]=='#'){
                x1 = i; 
                y1 = j;
                f=1;
            }
            if(s[i][j]=='#'){
                x2 = i;
                y2 = j;
            }
        }
    }
    cout<<(x1+x2)/2 + 1<<" "<<y1+1<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}