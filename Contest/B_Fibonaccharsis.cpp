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
    int n,k;
    cin>>n>>k;
    ll res =  0;
    for(int i=0 ; i<= n; i++){
        int a = i , b = n, tm = 2;
        while( tm<k && b-a <=a){
            int c = a;
            a = b-a;
            b = c;
            tm++ ;
            if(tm ==k){
                res++;
                break;
            }
        }
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