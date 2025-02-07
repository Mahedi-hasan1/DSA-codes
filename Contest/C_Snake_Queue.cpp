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
        int q; 
        cin>>q;
        int del = 0 ;
        vector<ll>v;
        v.pb(0);
        while(q--){
            ll a, b;
            cin>>a;
            if(a==1){
                cin>>b;
                v.pb(v[v.size()-1]+b);
            }
            else if(a==2){
                del++;
            }
            else{
                cin>>b;
                ll res = v[del + b-1];
            
                if(del>0){
                    res -= v[del];
                }
                cout<<res<<endl;
            }
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