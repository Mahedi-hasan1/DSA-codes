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
const ll mx = 1e6+5;
ll ned[mx];
int cnt = 0 ;
bool mark[mx];
int nd(int x, int pos, vector<int>&v){
    mark[x] = 1;
    if(ned[x] != -1) return ned[x];
    int tmp = x - pos, n = v.size();
    if(tmp<0)tmp += n; 
    else if (tmp==0) return ned[x] = 0 ;
    int cnt = tmp ;
    int j = 1 , i = pos;
    while(j<cnt){
        i%=n;
        if(mark[v[i]]){
            if(ned[v[i]]!=-1) tmp -= tmp>ned[v[i]]; 
        }
        else tmp -= (tmp>nd(v[i], i+1, v));
        i++;
        j++;
    }
    return ned[x] = tmp;
}


void solve(int tc)
{
    int n;
    cin>>n;
    for(int i=0 ; i<=n ; i++){
        ned[i] = - 1;
        mark[i] =0;
    }
    vector<int>v(n);
    for(int i=0 ; i<n; i++)cin>>v[i];

    //nd(v[1], 1+1, v);
    for(int i=0 ; i<n; i++){
        nd(v[i], i+1, v);
    }

    for(int i= 1; i<=n; i++)
        cout<<ned[i]<<" ";
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