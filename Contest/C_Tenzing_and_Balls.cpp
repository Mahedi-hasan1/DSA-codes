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
    ll ar[n+1];
    map<ll,ll>enlen, prepos;
    ll maxpos[n+1];
    memset(maxpos, 0, sizeof maxpos);
    for(int i =1 ; i<=n; i++){
        cin>>ar[i];
        if(prepos[ar[i]]) 
            maxpos[i] = max(maxpos[prepos[ar[i]]]+ i-prepos[ar[i]], 
                        maxpos[prepos[ar[i]]-1] + i - prepos[ar[i]]+1);
        maxpos[i] = max(maxpos[i-1], maxpos[i]);
        prepos[ar[i]] = i;
    }
    cout<<maxpos[n]<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}