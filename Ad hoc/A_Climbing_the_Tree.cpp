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
#define infl 2e18+5;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ll cal (ll len, ll a, ll b){
    if(len <= a)return 1;
    ll tmp = 1 + (len-a)/(a-b);
    if((len-a)%(a-b))tmp++;
    return tmp;

}

void solve(int tc)
{
    int q;
    cin>>q;
    ll x, a, b, d, l =0, r = infl;
    while(q--){
        cin>>x>>a>>b;
        if(x==1){
            cin>>d;
            ll tl , tr;
            tr = a + (a-b)*(d-1);
            tl = tr - (a-b) + 1;
            if(d==1)tl = 1;
            auto disjointt = [&](ll L1, ll R1, ll L2, ll R2) -> bool {
                if(L1>R2 or L2>R1) return true;
                return false;
            };
            if(!disjointt(l, r, tl, tr)){
                cout<<1<<" ";
                l = max(l, tl);
                r = min(r, tr);
            }
            else cout<<0<<" ";
        }
        else{
            ll tmp1 = cal(l, a, b);
            ll tmp2 = cal (r, a,b);
            if(tmp1 == tmp2)cout<<tmp1<<" ";
            else cout<<-1<<" ";
            
        }
        //cout<<" ( "<<l<<" "<<r<<" ) ";
    }
    cout<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}