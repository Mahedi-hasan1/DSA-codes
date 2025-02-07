#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define ff first
#define ss second


void solve(int tc)
{
    int n,k;
    cin>>n>>k;

    string s[n];
    for(int i=0 ;i<n;i++)cin>>s[i];

    for(int i=0 ; i<n; i+=k){
        for(int j=0 ; j<n; j+=k){
            cout<<s[i][j];
        }
        cout<<endl;
    }
}
    

int main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}