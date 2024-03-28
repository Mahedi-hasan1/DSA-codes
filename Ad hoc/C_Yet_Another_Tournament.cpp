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

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


void solve(int tc)
{
    ll n, m;
    cin>>n>>m;
    vector<ll>v(n),ar(n);
    for(int i=0 ; i<n; i++){
        cin>>v[i];
    }
    ar=v;
    sort(all(v));
    int pos = -1 ;
    for(int i=0 ; i<n; i++){
        if(m>=v[i]){
            m-=v[i];
            pos++;
        }
        else break;
    }
    int rank = n-pos;
    if(rank != 1 && pos != -1){
        if(ar[pos+1]<= v[pos]+m)rank--;
    }
    cout<<rank<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}