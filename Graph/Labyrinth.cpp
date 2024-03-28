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
const ll mx = 1e3+5;
string s[mx];
bool vis[mx][mx];
int ar[4] = {1, -1, 0 , 0};
int br[4] = {0 , 0 , 1, -1};
string path = "", res="" ;
bool ff = 0;
void dfs(int i, int j , int n, int m){
    if(vis[i][j] || s[i][j] =='#' )return;
    vis[i][j]=1;
    if(s[i][j]=='B'){
        ff=1;
        return;
    }
    for(int x=0 ; x<4; x++){
        if( 0<= i+ar[x] && i+ar[x]<n && 0<=j+br[x] &&  j+br[x] < m){
            if(vis[i+ar[x]][j+br[x]] ||  s[i+ar[x]][j+br[x]] =='#' )continue;
            char mov = 'x';
            if(x==0) mov = 'D';
            else if(x==1) mov = 'U';
            else if (x==2) mov = 'R';
            else mov = 'L';
            if(ff)return;
            path += mov;
            dfs(i+ar[x], j+br[x] , n ,m);
            if(ff)return;
            path.pop_back();
        }
    }

}

void solve(int tc)
{
    int n, m, x, y;
    cin>>n>>m;
    for(int i=0 ; i<n; i++){
        cin>>s[i];
    }
    for(int i=0 ; i<n; i++){
        for(int j=0 ; j<m; j++){
            if(s[i][j]=='A'){
                x=i, y = j;
                break;
            }
        }
    }
    dfs(x, y , n, m);
   // path = res;
    if(path.size()>=1){
        YES;
        cout<<path.size()<<endl;
        cout<<path<<endl;
    }
    else NO;
}
    

int main()
{
    fastio;
    int t = 1;
   // cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}