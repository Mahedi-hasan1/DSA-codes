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
    ll n;
    cin>>n;
    ll sum = 0 ;
    vector<ll>v;
    for(ll i=2; i*i <= n ;i++){
        while(n%i==0){
            sum += i;
            v.pb(i);
            n/= i;
        }
    }
    if(n>1){
        sum += n;
        v.pb(n);
    }
    cout<<"Case #"<<tc<<": ";
    if(sum<=41){
        cout<<v.size()+ 41-sum<<" ";
        for(int i=0 ; i<v.size() ; i++){
            cout<<v[i]<<" ";
        }
        for(int i=sum+1; i<=41 ; i++)cout<<1<<" ";
        cout<<endl;
    } 
    else cout<<-1<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}