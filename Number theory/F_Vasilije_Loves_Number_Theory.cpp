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
const ll mx = 1e6 + 1;
vector<vector<ll>> divs(mx);
void solve(int tc)
{
    ll n, q;
    cin >> n >> q;
    ll tmp = n, x, y;
    map<int, int> prmf, ins;
    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            prmf[i]++;
            n /= i;
        }
    }
    if (n > 1)
        prmf[n]++;
    ins = prmf;
    while (q--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            n = y;
            for (ll i = 2; i * i <= n; i++)
            {
                while (n % i == 0)
                {
                    prmf[i]++;
                    n /= i;
                }
            }
            if (n > 1)
                prmf[n]++;
            ll ndiv = 1 ;
            for(auto it : prmf){
                ndiv *= (it.s+1);
            }
            map<int,int>divp;
            for(ll i = 2; i*i<= ndiv; i++){
                while(ndiv%i==0){
                    divp[i]++;
                    ndiv/=i;
                }
            }
            if(ndiv>1)divp[ndiv]++;
            bool f = 1;
            for(auto it: divp){
                if(it.s> prmf[it.f])f=0;
            }
            if(f)YES;
            else NO;
        }
        else if(x==2){
            prmf = ins;
        }
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