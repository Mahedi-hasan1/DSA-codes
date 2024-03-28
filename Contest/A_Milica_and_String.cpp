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




void solve(int tc)
{
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt =0;
    for(int i=0 ; i<n; i++){
        if(s[i]=='B')cnt++;
    }
    if(cnt>k){
        int ned = cnt-k, tm= 0;
        for(int i=0 ; i<n; i++){
            if(s[i]=='B') tm++;
            if(tm==ned){
                cout<<1<<endl;
                cout<<i+1<<" A"<<endl;
                break;
            }
        }
    }
    else if(k>cnt){
        int ned = k -cnt,tm =0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='A')tm++;
            if(tm==ned) {
                cout<<1<<endl;
                cout<<i+1<<" B"<<endl;
                break;
            }
        }
    }
    else cout<<0<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}