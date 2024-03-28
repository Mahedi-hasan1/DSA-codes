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

const ll  mx = 1e6+1;
int cnt[mx];

void solve(int tc)
{
    int n;
    cin>>n;
    int ar[n];
    set<int>st;
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
        cnt[ar[i]]++;
        if(cnt[ar[i]]>=3) st.insert(ar[i]);
    }
    ll res = 0 ;
    for(auto it : st){
        ll tmp = cnt[it];
        res += (tmp*(tmp-1)*(tmp-2));
    }
    
    for(int i=0 ; i<n; i++){
        for(ll j = 2; j*j<=mx ; j++){
            ll tmp1 =ar[i]*j, tmp2 = tmp1*j;
            if(tmp2> mx)continue;
            res += cnt[tmp1] * cnt[tmp2]; 
        }
    }
    cout<<res<<endl;
    for(int i=0 ; i<n; i++)cnt[ar[i]]=0;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}