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

vector<int>primes;

void solve(int tc)
{
    int n;
    cin>>n;
    ll ar[n];
    set<ll>st;
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
        st.insert(ar[i]);
    }
    if(st.size() != n){
        NO;
        return;
    }

    for(int i=0 ; i< primes.size() ; i++){
        ll tmp = primes[i];
        map<int,int>cnt;
        for(int j =0 ;j<n; j++){
            cnt[ar[j]%tmp]++;
        }
        bool f = 1;
        for(int j=0 ; j<tmp ; j++){
            if(cnt[j]<2)f=0;
        }
        if(f){
            NO;
            return;
        }
    }
    YES;

}
    

int main()
{
    fastio;
    int t = 1;
    bool mark[100];
    memset(mark, 1, 100);
    for(int i=2; i<=100; i++){
        if(mark[i])primes.pb(i);
        for(int j=i*i; j<=100; j+=i)mark[j]=0;
    }
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}