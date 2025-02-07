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

const ll mx = 2e5+5;
bool visited[mx];


void dfs(int st, vector<vector<int>>&graph){
    visited[st]=1;

    for(int i=0 ; i<graph[st].size() ; i++){
        if(visited[graph[st][i]])
            continue;
        dfs(graph[st][i], graph);
    }
}

void solve(int tc)
{
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>val(n+1,vector<int>(11,0));
    map<ll,bool>connected;
    connected.clear();
    vector<vector<int>>graph(n+1);
    graph.clear();
    
    for(int i=0 ; i<m; i++){
        int a,d,k;
        cin>>a>>d>>k;
        val[a][d]=max(val[a][d],k);
    }

    for(int i=1; i<=n;i++){
        visited[i]=0;
        for(int d =1 ; d<=10 ; d++){
            if(val[i][d] !=0){
                if(i+d>n)
                    continue;
                val[i+d][d] = max(val[i+d][d], val[i][d]-1);

                if(connected[i*mx+(i+d)] == 0 ){
                    //cout<<i<<" "<<i+d<<endl;
                    graph[i].pb(i+d);
                    graph[i+d].pb(i);
                    connected[i*mx+(i+d)] = 1;
                }
            }
        }
    }
    int cnt =0 ;
    for(int i=1 ; i<=n ; i++){
        if(visited[i]==0){
            dfs(i,graph);
            cnt ++;
        }
    }
    cout<<cnt<<endl;

}
    

int main()
{
    //fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}