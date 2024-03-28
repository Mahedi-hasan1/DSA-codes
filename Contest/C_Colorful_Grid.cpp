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
    int n,m, k;
    cin>>n>>m>>k;
    if(n+m-2>k || (k-n-m+2)%2){
        NO;
        return;
    }
    YES;
    
    vector<vector<char>>ar(n, vector<char>(m-1, 'B')), ar2(n-1, vector<char>(m, 'B'));
    
    char c = 'R';
    for(int i=0 ; i<m-1; i+=2){
        ar[0][i]=c;
    }
    ar[1][0]=c;
    int i =0 ;
    if(m%2==0)i++;
    for( ; i<n-1; i+=2)
        ar2[i][m-1] = c;
    if(ar2[n-2][m-1]=='B'){
        ar2[n-2][m-2] = 'R';
    }
    else {
        ar[n-1][m-2] = 'R';
        ar[n-2][m-2] = 'R';
    }


    for(int i=0 ; i<n; i++){
        for(int j=0 ; j<m-1; j++)cout<<ar[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<m; j++)cout<<ar2[i][j]<<" ";
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