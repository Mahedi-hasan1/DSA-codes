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
ll px, py, ax, ay , bx, by;
ll dd1, dd2, dd3, dd4, dd5;

bool pos(ll m){
    bool f =0 , f1 =0;
    if(m >= dd1)f=1;
    if(m>=dd2)f1=1;
    if(m>=dd3)f=1;
    if(m>=dd4)f1=1;
    return f&f1;
}
void solve(int tc)
{
    
    cin>>px>>py>>ax>>ay>>bx>>by;
    if(px ==0 && py==0){
        cout<<0<<endl;
        return;
    }
    dd1 = (px-ax)*(px-ax) + (py-ay)*(py-ay);
    dd2 = (ax)*(ax) + (ay)*(ay);

    dd3 = (px-bx)*(px-bx) + (py-by)*(py-by);
    dd4 = (bx)*(bx) + (by)*(by);

    dd5 = (ax-bx)*(ax-bx) + (ay-by)*(ay-by);

    ll res = max(dd1, dd2);
    res = min(res, max(dd3, dd4));
    ll tmp1, tmp2;
    tmp1 = min(dd1, dd3);
    tmp2 = min(dd2, dd4);
    double tmp3 = dd5/4.0;

    double tmp = max({(double)tmp3, (double)tmp1, (double)tmp2});
    
    tmp = min(tmp, double(res));
    
    cout<<fixed<<setprecision(8)<<sqrt(tmp)<<endl;


}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}