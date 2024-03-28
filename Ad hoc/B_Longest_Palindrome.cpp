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

ll pallen(string &s){
    int m = s.size();
    for(int i=0; i<m/2; i++){
        if(s[i] != s[m-1-i])return 0;
    }
    return s.size();
}

void solve(int tc)
{
    string s;
    cin>>s;
    int n = (int)s.size();
    ll mn = 1;
    for(int i=0 ; i<n ; i++){
        string tmp ="";
        tmp+=s[i];
        for(int j= i+1; j<n; j++){
            tmp+= s[j];
            mn = max(mn, pallen(tmp));
        }
    }
    cout<<mn<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}