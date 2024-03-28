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

int nxtx(int a, string s)
{
    if (s[0] == 'D')
        a++;
    else
        a--;
    return a;
}

int nxty(int a, string s)
{
    if (s[1] == 'L')
        a--;
    else
        a++;
    return a;
}
bool mark(string &s, int &x, int &y , vector<vector<bool>>&dl, vector<vector<bool>>&dr, vector<vector<bool>>&ul, vector<vector<bool>>&ur){
    if(s=="DL"){
        if(dl[x][y]==1) return 0 ;
        else dl[x][y]=1;
    }
    else if(s=="DR"){
        if(dr[x][y]==1)return 0;
        else dr[x][y]=1;
    }
    else if(s== "UL"){
        if(ul[x][y]==1)return 0 ;
        else ul[x][y] =1;
    }
    else {
        if(ur[x][y]==1)return 0;
        else ur[x][y] = 1;
    }
    return 1;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;
    int x, y, x2, y2;
    string s;
    cin >> x >> y >> x2 >> y2 >> s;
    vector<vector<bool>>dl(n, vector<bool>(m,0)),dr(n, vector<bool>(m,0)),
     ul(n, vector<bool>(m,0)), ur(n, vector<bool>(m,0)) ;
    bool fnd =0 ;
    int cnt = 0 ;
    x--;
    y--;
    while (1)
    {
        if(x==x2-1 && y == y2-1){
            fnd =1;
            break;
        }

        if(mark(s, x,y , dl, dr, ul, ur)==0){
            break;
        }
        int nx = nxtx(x, s);
        int ny = nxty(y, s);
        int f = 0 ;
        if (ny >= m)
        {
            if (s[1] == 'R')
                s[1] = 'L';
            else
                s[1] = 'R';
            ny -= 2;
            f=1;
        }
        if (nx >= n)
        {
            if (s[0] == 'U')
                s[0] = 'D';
            else
                s[0] = 'U';
            nx -= 2;
            f=1;
        }
        if (nx < 0)
        {
            if (s[0] == 'U')
                s[0] = 'D';
            else
                s[0] = 'U';
            nx += 2;
            f=1;
        }
        if(ny<0){
            if (s[1] == 'R')
                s[1] = 'L';
            else
                s[1] = 'R';
            ny += 2;
            f=1;
        }
        if(f)cnt++;
        x=nx;
        y=ny;
    }
    //cout<<fnd<<endl;
    if(fnd)cout<<cnt<<endl;
    else cout<<-1<<endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}
