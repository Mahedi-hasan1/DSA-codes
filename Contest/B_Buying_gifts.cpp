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
    int n;
    cin>>n;
    vector<pair<ll,ll>>vp(n);
    for(int i=0 ;i <n; i++){
        cin>>vp[i].f>> vp[i].s;
    }

    sort(all(vp));
    ll bmx[n],mx =0;
    for(int i = n-1; i>=0 ; i--){
        mx = max(vp[i].s, mx);
        bmx[i]=mx;
    }
    ll res = INT_MAX;
    set<ll>st;
    for(int i=0 ; i<n; i++){
        ll tmp = vp[i].f;
        ll tmp2 = -INT_MAX;
        if(i<n-1){
            tmp2= bmx[i+1];
        }
        ll ans = abs(tmp-tmp2);
        if(!st.empty()){
            auto it = st.lower_bound(tmp);
            if(it==st.end())it--;
            ans = min(ans, abs(tmp- max(tmp2, *it)));
            if(it != st.begin()){
                it--;
                ans = min(ans, abs(tmp-max(tmp2,*it)));
            }
        }
        res = min(res, ans);
        st.insert(vp[i].s);
    }
    cout<<res<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}