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
int mx = 8e5+5;
vector<int>ar(mx),mem(mx);

void bild(int x, int l , int r ){
    if(l==r){
        mem[x]=ar[l];
        return;
    }

    int m = (l+r)/2;
    bild(2*x, l , m);
    bild(2*x+1, m+1 , r);
    mem[x]= mem[2*x]+ mem[2*x+1];
}

ll upd(int x, int l , int r , int i , int a){
    if(i < l && i> r)return mem[x];
    if(l==r && l == i ){
        return mem[x]= a;
        
    }

    int m = (l+r)/2;
    ll l = (2*x, l, m , i , a);
    ll r = (2*x+1, m+1, r , i , a);
    return mem[x] = l + r;
}

ll qry(int x, int l , int r , int i , int j){
    if(j<l || i>r)return 0;
    if(i>= l && j <= r)return mem[x];
    if(l==r) return mem[x];
    ll m = (l+r)/2;
    ll l = qry(x*2,l, m , i, j);
    ll r = qry(x*2+1, m+1, r , i , j);
    return  l+r;
}


void solve(int tc)
{
    int n,q;
    cin>>n>>q;
    for(int i =1 ;i<=n; i++)cin>>ar[i];
    bild(1, 1, n);
    while(q--){
        int a, i , j;
        cin>>a>>i>>j;
        if(a==1){
            upd(1, 1, n, i, j);
        }
        else {
            qry(1, 1, n ,i, j);
        }
    }


}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}