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
    int n, x;
    cin>>n>>x;
    vector<pair<int,int>>ar(n), br(n), ans(n);
    for(int i=0,a; i<n; i++){
        cin>>a;
        ar[i] = {a,i};
    }
        
    for(int i =0,a ; i<n; i++){
        cin>>a;
        br[i] = {a,i};
    }
        

    sort(all(ar));
    sort(all(br));

    int j =0 ;
    bool f = 1;
    for(int i =n-x ; i<n; i++){
        ans[i] = {br[j].ff, ar[i].ss};
        j++;
    }
    for(int i = 0 ; i<n-x; i++){
        ans[i] = {br[j].ff, ar[i].ss};
        j++;
    }

   
    for(int i=0 ; i<n; i++){
        swap(ans[i].ff , ans[i].ss);
        swap(ar[i].ff, ar[i].ss);
    }
    sort(all(ans));
    sort(all(ar));

    int cnt =0 ;
    for(int i=0 ; i<n; i++){
        if(ar[i].ss > ans[i].ss)cnt++;
    }

    if(cnt != x) NO;
    else {
        YES;
        for(int i=0 ; i<n; i++)cout<<ans[i].ss<<" ";
        cout<<endl;
    }
    

}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}