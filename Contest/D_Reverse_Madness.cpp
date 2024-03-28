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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>ar(k), br(k);
    for(int i=0 ; i<k ; i++)cin>>ar[i];
    for(int i=0 ; i<k ; i++)cin>>br[i];
    int cnt[n+5];
    memset(cnt, 0 , sizeof cnt);
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        int l = 0 , r = k;
        while(r-l > 1){
            int m = (r+l)/2;
            if(ar[m]<= x){
                l = m;
            }
            else {
                r = m;
            }
        }
        int lr = min(x, ar[l]+br[l]-x), rr = max(x, ar[l]+br[l]-x);
        cnt[lr-1]++;
        cnt[min(n, rr)]--;
    }
    int tmp = 0 ;
    for(int i=0 ; i<=n; i++){
        tmp += cnt[i];
        cnt[i]=tmp;
    }
    
    for(int i = 0  ; i<k ;i++){
        int j = ar[i]-1, n = br[i]-1;
        int k = n, ls = (j+n)/2;
        for( ; j<= ls; j++){
            //cout<<j<<" "<<k<<endl;
            if(cnt[j]%2)swap(s[j], s[k]);
            k--;
        }
    }
    cout<<s<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}