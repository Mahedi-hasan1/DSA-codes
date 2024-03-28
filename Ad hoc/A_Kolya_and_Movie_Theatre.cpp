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
        ll n, m, d;
        cin>>n>>m>>d;
        set<pair<ll,ll>>st;
        ll res = 0 , sum = 0;
        for(ll i=0,a ; i<n; i++){
            cin>>a;
            res = max (res, sum+ a -((i+1)*d));
            if(a>0){
                st.insert({a,i});
                sum += a;
                if(st.size()== m){
                    pair<ll,ll> p = *st.begin();
                    st.erase(p);
                    sum-=p.f;
                }
            }
        }
        cout<<res<<endl;
    }
        

    int main()
    {
        fastio;
        int t = 1;
        cin >> t;
        for (int i = 1; i <= t; i++)
            solve(i);
    }