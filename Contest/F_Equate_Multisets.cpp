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
    ll ar[n],  br[n];
    map<int,int>cnt;
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
        while(ar[i]%2==0)ar[i]/=2;
        cnt[ar[i]]++;
    }
    bool f = 1, ans = 1;
    for(int i=0 ; i<n; i++){
        cin>>br[i];
    }
    for(int i=0 ; i<n; i++){
        ll tmp = br[i];
        f=0;
        while(tmp<= 1e9){
            if(cnt[tmp]){
                cnt[tmp]--;
                f=1;
                break;

            }
            tmp *= 2;
        }
        if(f)continue;
        tmp = br[i];
        while(tmp>0){
            if(cnt[tmp]){
                cnt[tmp]--;
                f=1;
                break;

            }
            if(tmp==1)break;
            tmp /= 2 ;
        }
        if(f)continue;
        while(tmp<= 1e9){
            if(cnt[tmp]){
                cnt[tmp]--;
                f=1;
                break;

            }
            tmp *= 2 ;
        }
        if(f==0){
            ans =0;
        }
    }
    if(ans)YES;
    else NO;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}