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
      int n, k;
      cin>>n>>k;
      string s;
      cin>>s;
      
      long long res = 1, mn = LONG_MAX, mx=1 ,taken =0 ;
      
      for(int i=0 ; i<k; i++){
        if(s[i]=='0'){
            res = 1;
            taken=0;
            continue;
        }
        taken++;
        res *= (s[i]-'0');
        if(taken <= n){
            //cout<<res<<" ";
            mn = min(mn, res);
            mx = max(mx, res);
            taken --;
            res /= (s[i-n+1]-'0');
        }
      }
      if(mn == LONG_MAX)mn = 1;
      cout << "case:" << tc << " " << endl;
      cout<<mx<<endl<<mn<<endl;
      //cout<<endl;
}
    
int main()
{
    //fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}