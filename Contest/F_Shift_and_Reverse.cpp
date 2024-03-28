#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr)

#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()

#define ff first
#define ss second

#define No cout << "No\n"
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"

ll ned(vector<int>&v){
    int n = v.size(), inf = INT_MAX;
    int pos=0 , f=0; 
    for(int i =1 ; i<n; i++){
        pos = i;
        if(v[i]<v[i-1]){
            f=1;
            break;
        }
    }
    if(!f)return 0 ;
    for(int i=pos+1; i<n; i++){
        if(v[i]<v[i-1]){
            return inf;
        }
    }
    if(v[n-1]>v[0])return inf;
    return n - pos;
}

void solve(int tc)
{
    int n;
    cin>>n;
    vector<int>v(n,0), v1(n,0);
    for(int i=0 ; i<n; i++){
        cin>>v[i];
        v1[i] = v[i];
    }
    reverse(v.begin(), v.end());
    ll res = ned(v1);
    
    res = min({res, abs(n-res)+2, min(ned(v), abs(n-ned(v)))+1});

    if(res>1e7)cout<<-1<<endl;
    else cout<<res<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}