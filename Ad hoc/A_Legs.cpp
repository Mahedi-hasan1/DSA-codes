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
    int n; cin>>n;
    int cnt = n/4;
    if(n%4)cnt++;
    cout<<cnt<<endl;
}
    

int main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}