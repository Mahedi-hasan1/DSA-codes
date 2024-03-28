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

int pcs(vector<int> &v){
    bool f = 0 ;
    for(int i=0 ; i<v.size() ; i++)if(v[i]==2)f=1;
    if(f)return 2;
    return 1;
}

void solve(int tc)
{
    int n, res = 0;
    cin>> n;
    vector<int>ar(n,0),mark(n,0), cri;
    for(int i=0 ; i<n ; i++){
        cin>>ar[i];
    }
    int cnt = 0 ;
    vector<int>v;
    for(int i=0 ; i<n; i++){
        if(ar[i] != 0){
            v.pb(ar[i]);
            cnt = 0 ;
        }
        else{
            if(v.size())cri.pb(pcs(v));
            v.clear();
            if(cnt<2)cri.pb(ar[i]);
            else res++;
            cnt++;
        }
    }
    if(v.size())cri.pb(pcs(v));
    n = cri.size();
    for(int i=0 ; i<cri.size() ; i++){
        if(cri[i]==2){
            res++;
            mark[i]=1;
            if(i-1>=0)mark[i-1]=1;
            if(i+1<n) mark[i+1]=1;
        }
    }
    for(int i=0 ; i<cri.size() ; i++){
        if(cri[i]==1){
            res++;
            mark[i]=1;
            if(i-1>=0 && mark[i-1]==0)mark[i-1]=1;
            else if(i+1<n && mark[i+1]==0) mark[i+1]=1;
        }
    }
    for(int i=0 ; i<n; i++)if(mark[i]==0)res++;

    cout<<res<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}