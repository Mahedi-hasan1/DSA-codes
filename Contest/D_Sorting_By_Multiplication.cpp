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
    vector<int>v(n);
    for(int i=0 ; i<n; i++)
        cin>>v[i];
    int eq = 0 ,dw = 0;
    for(int i = 1 ; i<n; i++){
        if(v[i]>v[i-1]){
            res += eq;
            eq = 0 ;
            continue;
        }
        else if(v[i] == v[i-1]){
            eq++;
        }
        else {
            res += eq; 
            eq = 0 ;

            dw ++;
        }
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