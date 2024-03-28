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
bool ans = true;
pair<ll,ll>chk(ll ned){
    ll take = 1;
    while(take<=ned)take*=2;
    ll ex = take - ned;
    ll tmp2 = 1;
    while(tmp2<ex)tmp2*= 2;
    if(tmp2 != ex)ans=0;
    return {take, ex};

}

void solve(int tc)
{
    int n;
    cin>>n;
    ll ar[n], sum = 0 ;
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
        sum += ar[i];
    }
    if(sum%n){
        no;
        return;
    }
    ll av = sum/n;
    map<ll,ll>bl;
    ans = true;
    for(int i=0 ; i<n; i++){
        ll ned = abs(ar[i]- av);
        if(ned==0)continue;
        if(ar[i]>av){
            bl[chk(ned).f]++;
            bl[chk(ned).s]--;
        }
        else {
            bl[chk(ned).s]++;
            bl[chk(ned).f]--;
        }
    }
    for(auto it : bl){
        if(it.s)ans = false;
    }
    if(ans)yes;
    else no;
    
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}