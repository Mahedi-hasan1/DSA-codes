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
    for(int i=0 ;i<n; i++)
        cin>>s[i];
    
    int cnt =0, tmp = 0 , f=1 ;
    for(int i=0;i<n; i++){
        cnt =0;
        for(int j=0 ;j<n; j++) {
            cnt += (s[i][j]-'0');
        }
        if(f && cnt){
            tmp = cnt;
            f=0;
        }
        if(cnt && cnt != tmp) {
            cout<<"TRIANGLE"<<endl;
            return;
        }
    }
    cout<<"SQUARE"<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}