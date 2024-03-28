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
int ar[8] = {1, -1, 0 , 0 , 1, 1 , -1, -1 };
int br[8] = {0, 0, 1 , -1 , 1, -1 , 1, -1 };

bool chk(int i, int j, int i2, int j2, int i3, int j3, vector<string>&s){
    bool f = 1;
    int n = s.size(), m = s[0].size();
    for(int k = 0 ; k< 8 ; k++){
        if(i+ar[k] == i2 && j+br[k]==j2)continue;
        if(i+ar[k] == i3 && j+br[k]==j3)continue;
        if(i+ar[k]<0 || i+ar[k]>=n || j+br[k]<0 || j+br[k]>=m)continue;

        if(s[i+ar[k]][j+br[k]]!='.')f=0;
    }
    return f;
}

bool chkout(int i1, int j1, int i2, int j2, int i3, int j3, vector<string>&s)
{
    int f = 1;
    f &= chk(i1, j1, i2, j2, i3, j3, s);
    f &= chk(i2, j2, i1, j1, i3, j3, s);
    f &= chk(i3, j3, i1, j1, i2, j2, s);
    if(f){
        s[i1][j1]='X';
        s[i2][j2]='X';
        s[i3][j3]='X';
    }
    return f;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    vector<string>s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    bool ans = 1 , f , f2 =0  ; 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '*')
            {
                if (i-1>=0 && s[i - 1][j] == '*' && j-1>=0 && s[i][j-1]=='*'){
                    chkout(i-1, j, i, j, i, j-1, s);
                }
                else if (i-1>=0 && s[i - 1][j] == '*' && j+1<m && s[i][j+1]=='*'){
                    chkout(i-1, j, i, j, i, j+1, s);
                }
                else if (i+1<n && s[i + 1][j] == '*' && j-1>=0 && s[i][j-1]=='*'){
                    chkout(i+1, j, i, j, i, j-1, s);
                }
                else if (i+1<n && s[i + 1][j] == '*' && j+1<m && s[i][j+1]=='*'){
                    chkout(i+1, j, i, j, i, j+1, s);
                }
            }
        }
    }
    for(int i=0 ; i<n; i++){
        for(int j=0 ; j<m; j++){
            if(s[i][j] == '*')ans = 0 ;
        }
    }
    if(ans)YES;
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