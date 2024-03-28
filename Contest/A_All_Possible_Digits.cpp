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
    ll n, b;
    cin>>n>>b;
    map<int,bool>cnt;
    ll ar[n];
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
        cnt[ar[i]]=1;
    }
    if(n==1){
        if(ar[0] != 2){
            cout<<b-1<<endl;
        }
        else cout<<b-2<<endl;
        return;
    }
    ll op = 0 , f = 0, tmp = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (ar[i] < b - 1) {
            tmp = ar[i] + 1;
            break;
        }
    }
    for(int i = ar[n-1]-1; i>=0 ; i--){
        if(cnt[i]==0){
            f++;
            if(i == tmp){
                op = max(op, b-ar[n-1]);
            }
            else op = max(op, b-ar[n-1]+i);
        }
        if(f>=2)break;
    }
    for(int i=b-1; i>=0 && i>ar[n-1]; i--){
        if(cnt[i]==0){
            op = max(op, i-ar[n-1]);
            break;
        }
    }
    cout<<op<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}