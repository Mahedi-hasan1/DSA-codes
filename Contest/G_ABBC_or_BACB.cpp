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
    string s;
    cin>>s;
    vector<ll>aa,bb;
    ll sum = 0 ;
    ll n = (int)s.size();
    ll tmp =1;
    for(int i=1 ; i<n; i++ ){
        if(s[i]==s[i-1])tmp++;
        else {
            if(s[i]=='B')aa.pb(tmp);
            else bb.pb(tmp);
            tmp=1;
        }
    }
    
    if(s[n-1]=='A')aa.pb(tmp);
    else bb.pb(tmp);
    tmp = 0;
    bool f = 0 ;
    //cout<<aa.size()<<" "<<bb.size()<<endl;
    for(int i=0 ; i<bb.size() ; i++){
        if(bb[i]>=2)f=1;
    }
    if( ((int)aa.size() <=  (int)bb.size()) || f ){
        for(int i=0 ; i<aa.size() ; i++)sum+= aa[i];
        cout<<sum<<endl;
        return;
    }
    
    sort(rall(aa));
    for(int i=0 ; i< (int)aa.size() -1 ; i++){
        sum+= aa[i];
    }
    cout<<sum<<endl;
    
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}