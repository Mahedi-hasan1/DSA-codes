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


void solve(int tc)
{
    int n;
    cin>>n;
    vector<ll>d(n), c(n);
    for(int i=0 ; i<n;i++)
        cin>>d[i];
    map<ll,ll>cnt;

    for(int i=0 ; i<n; i++){
        cin>>c[i];
        cnt[i+1]=0;
    }
    
    set<pair<ll,ll>>st;
    for(int i=1 ; i<=n; i++){
        st.insert({0, i});
    }
    for(int i=0 ; i<n; i++){
        ll a = cnt[d[i]];
        st.erase({a, d[i]});
        cnt[d[i]]+= c[i];
        a=cnt[d[i]];
        st.insert({a, d[i]});
    }
    map<ll,ll>mark;
    
    while(!st.empty()){
        auto tmp = *st.begin();
        cout<<tmp.ss<<" ";
        mark[tmp.ss]=1;
        st.erase(tmp);
         ll a = cnt[d[tmp.ss-1]];
         st.erase({a, d[tmp.ss-1]});
         a -= c[tmp.ss-1];
         cnt[d[tmp.ss-1]] = a;
         if(mark[d[tmp.ss-1]])continue;
         st.insert({a,d[tmp.ss-1]});

    }
    cout<<endl;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}