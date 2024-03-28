 #include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;


#define ll long long int
#define pb push_back
#define show(x) cout << #x << " : " << x << endl;

#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()


void solve(int tc)
{
    ll n;
    cin >> n;

    ll neg = 0;
    for(int i=0; i<n; i++)
    {
        ll x; 
        cin >> x;
        if(x<0)
            neg++;
    }
    n /= 2;
    if(neg >= n){
        ll tem  = neg - n;
        
        cout << neg - n << endl;
    }
    else
    {
        if(neg & 1)
            cout << 1 << endl;
        else 
            cout << 0 << endl;
    }

}
    

int main()
{
    
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}