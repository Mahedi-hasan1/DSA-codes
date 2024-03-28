
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
ll n;

ll segsum(ll a, ll b ){
    ll tmp = ((b-a)*(b+a+1))/2;
    return tmp;
}
bool pos(ll m,ll k){
    ll sum = segsum(n-m+1, n);
    if(sum<k)return 1 ;
    return 0;
}

void solve(int tc)
{
    string s;
    cin>>s;
    ll k;
    cin>>k;
    n = s.size();
    ll l =0 , r = n+1;
    while(r-l>1){
        ll m = (r+l)/2;
        if(pos(m, k)){
            l = m;
        }
        else r = m;
    }
    ll pos = k - segsum(n-l+1, n);
    ll cnt = l;
    l=0 , r = 1;
    vector<int> mark(n+1, 0);
    ll tmp = 1;
    vector<int>ls;
    while(l<n && r<n){
        if(s[l]>s[r]){
            mark[l]=tmp;
            tmp++;

            if(!ls.empty()){
                l = ls[ls.size()-1];
                ls.pop_back();
            }
            else{
                l=r;
                r++;

            }
        }
        else {
           ls.pb(l);
           l=r;
           r++;
        }
    }
    for(int i=n-1; i>=0 ; i--){
        if(mark[i]==0){
            mark[i]=tmp;
            tmp++;
        }
    }
    string p="";
    
    for(int i=0 ; i<n; i++){
        if(mark[i]>=cnt)p+=s[i];
    }
    cout<<p[pos-1];

}


int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
