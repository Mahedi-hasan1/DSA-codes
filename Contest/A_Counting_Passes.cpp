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
        int n,l;
        cin>>n>>l;
        int cnt =0;
        for(int i=0,a; i<n; i++){
            cin>>a;
            if(a>=l)cnt++;
        }
        cout<<cnt<<endl;

    }
        

    int main()
    {
        fastio;
        int t = 1;
        //cin >> t;
        for (int i = 1; i <= t; i++)
            solve(i);
    }