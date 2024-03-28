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


void solve(int tc)
{
    int n;
    cin>>n;
    int ar[n];
    int a=0 , b = 0 , c = 0;
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
        if(i+1 == ar[i])a++;
        else if(n-i == ar[i])b++;
        else c++;
    }
    if(a>= b+c)cout<<"First"<<endl;
    else if(b > a+c)cout<   <"Second"<<endl;
    else cout<<"Tie"<<endl;
    
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}