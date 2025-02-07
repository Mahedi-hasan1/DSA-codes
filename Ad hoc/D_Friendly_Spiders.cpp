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
const ll mx = 3e5+5;
vector<vector<ll>>factrs(mx), avlmuls(mx);
vector<bool>factrsvis(mx), mulsvis(mx);
vector<ll>par(mx);

void solve(int tc)
{
    ll n, l , r;
    cin>>n;
    vector<ll>ar(n);
    
    for(int i =0 ; i<n; i++)
        cin>>ar[i];
    
    cin>>l>>r;
    
     for(int i=0 ; i<n; i++){
         ll tmp = ar[i];

         for( ll j = 2; j*j <= tmp ; j++){
             if(tmp % j==0) {
                 factrs[i].pb(j);
                 avlmuls[j].pb(i);
             }
             while(tmp%j==0){
                 tmp /= j;
             }
          }
          if(tmp>1){
              factrs[i].pb(tmp);
              avlmuls[tmp].pb(i);
          }
     }

    l--; r--;
    if(l==r){
        cout<<1<<endl<<l+1<<endl;
        return;
    }
    ll st = l;
    bool pos = 0 ;
    queue<ll>qu;
    int x =0 ;
    qu.push(st);
    while(!qu.empty()){
        st = qu.front();
        mulsvis[st]=1;
        qu.pop();
        for(int i=0 ; i<factrs[st].size() ; i++){
            ll tmp = factrs[st][i];
            if(factrsvis[tmp])continue;
            factrsvis[tmp]=1;

            for(int j=0 ; j<avlmuls[tmp].size() ; j++){
                
                ll tmp2 = avlmuls[tmp][j];

                //cout<<tmp<<tmp2<<endl;
                if(mulsvis[tmp2])continue;
                mulsvis[tmp2]=1;
                par[tmp2]=st;
                qu.push(tmp2);
                if(tmp2==r){
                    pos = 1;
                    break;
                }
                

            }

            if(pos)break;
        }
        if(pos)break;
    }
    if(pos==0){
        cout<<-1<<endl;
    }
    else{
        vector<ll>ans;
        ll tmp = r;
        while(tmp != l){
            ans.pb(tmp);
            tmp = par[tmp];
        }
        ans.pb(l);
        reverse(all(ans));
        cout<<ans.size()<<endl;;
        for(int i =0 ;i<ans.size() ; i++)
            cout<<ans[i]+1<<" ";
    }

}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}