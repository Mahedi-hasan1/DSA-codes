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

const ll mx = 3e5+5;
vector<vector<int>>v(mx), v2(mx);
vector<bool>visval(mx), visp(mx);
vector<int>pr(mx);

void solve(int tc)
{
    int n;
    cin>>n;
    int ar[n];
    for(int i =0 ; i<n; i++)
        cin>>ar[i];
    int s, t;
    cin>>s>>t;
    for(int i=0 ; i<n; i++){
        ll tmp = ar[i];
        for(int j= 2; j<=548 && j*j<=tmp  ; j++){
            bool f = 0 ;
            while(tmp%j == 0){
                tmp/=j;
                f=1;
            }
            if(f) {
                v[j].pb(i);
                v2[i].pb(j);
            }
        }
        if(tmp>1){
            v[tmp].pb(i);
            v2[i].pb(tmp);
        }
    }
    int st = s-1, en = t-1;
    if(st==en){
        cout<<1<<endl;
        cout<<st+1<<endl;
        return;
    }
    queue<int>q;
    q.push(st);
    bool res =0 ;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0 ; i<v2[cur].size() ; i++){
            int curp = v2[cur][i];
            if(visp[curp])continue;
            visp[curp]=1;
            for(int j = 0 ; j<v[curp].size() ; j++){
                int tmp = v[curp][j];
                if(visval[tmp])continue;
                pr[tmp]=cur;
                visval[tmp]=1;
                q.push(tmp);
                if(tmp==en){
                    res = 1;
                    break;
                }
            }
            if(res)break;
        }
        if(res)break;
    }
    if(res){
        vector<int>ans;
        ll tmp = en;
        ans.pb(en);
        while(tmp!=st){
            tmp = pr[tmp];
            ans.pb(tmp);
        }
        reverse(all(ans));
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++){
            cout<<ans[i]+1<<" ";
        }
        cout<<endl;
    }
    else cout<<-1<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}