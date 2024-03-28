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
    int ar[n];
    for(int i=0 ; i<n; i++)
        cin>>ar[i];
    
    bool f = 0 ;
    while(1){
        f=0;
        for(int i=1 ; i<n-1; i++){
            if(ar[i]>ar[i-1] && ar[i]>ar[i+1]){
                swap(ar[i], ar[i+1]);
                f=1;
                break;
            }
        }
        if(f==0)break;
    }
    f=0;
    for(int i=1; i<n; i++)if(ar[i]<ar[i-1])f=1;

    if(f)NO;
    else YES;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}