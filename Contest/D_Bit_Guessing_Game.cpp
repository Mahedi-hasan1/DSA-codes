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

ll twop(ll n){
    ll res = 1;
    for(int i =0 ; i<n; i++)res*=2;
    return res;
}

void solve(int tc)
{
    ll res = 0 , prv , n,  ptr=0,now;
    cin>>prv;
    ll n = prv, i=0;
    while(i<n){
        cout<<"- "<<twop(ptr)<<endl;
        cin>>now;
        if(now<prv){
            res += twop(ptr);
        }
        else {
            ptr += (now-prv+1);
            res+= twop(ptr);
        }
        ptr++;
        i++;
        prv = now;
    }
    cout<<"! "<<res<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}