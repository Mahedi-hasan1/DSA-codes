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

ll opned(ll a, ll b){
    ll op = 2;
    if(a==b && a ==0){
        return -1;
    }
    while(1){
        //cout<<a<<" "<<b<<" "<<op<<endl;
        if(a== 0 || a==b){
            if(a==0)op--;
            else op++;
            return op;
        }
        if(b>a){
            op++;
            ll c = abs(b-a);
            a = b;
            b = c;
        }
        else {                               
           ll dif = abs(a-b) ;
           ll tmp = a/dif + 1;
           if(tmp == 2){
                op+=2;
                a = abs(a-b);
                b = abs(a-b);
           }
           else {
            tmp += (tmp+1)/2;
            tmp -= 2;
            op += tmp;
            a = a % dif;
            b = abs(a-dif); 
           }
        }
    }
    return op;
}                 

void solve(int tc)
{
    int n;
    cin>>n;
    int ar[n], br[n];
    set<ll>st;
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
    }
    for(int i=0; i<n; i++){
        cin>>br[i];
           
        if(opned(ar[i], br[i]) == -1)continue;
       //cout<<opned(ar[i], br[i])<<endl;
        st.insert(opned(ar[i], br[i])%3);
    }
    if(st.size() == 1)YES;
    else NO;

}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}