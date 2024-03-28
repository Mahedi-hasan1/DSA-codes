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

ll except(int x, vector<vector<int>>&v){
    set<int>st;
    for(int i=0 ; i<v.size() ; i++){
        bool f = 0;
        for(int j=0 ; j<v[i].size() ; j++){
            if(v[i][j]==x)f=1;
        }
        if(f)continue;
        else{
            for(int j=0 ; j<v[i].size() ; j++)
                st.insert(v[i][j]);

        }
    }
    return st.size();
}

void solve(int tc)
{
    int n;
    cin>>n;
    set<int>st;
    vector<vector<int>>v(n);
    for(int i=0 ,k; i<n ; i++){
        cin>>k;
        for(int j =0 ,x; j<k;  j++){
            cin>>x;
            v[i].pb(x);
            st.insert(x);
        }
    }
    ll res =  0 ;
    for(auto it : st){
        res = max(res, except(it, v));
    }
    cout<<res<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}