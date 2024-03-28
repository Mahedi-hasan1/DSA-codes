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

void file(){
    const string ipath = "../files/in.txt";
    const string opath = "../files/ou.txt";
    ifstream input_file(ipath);
    ofstream output_file(opath);
}
void solve(int tc)
{
    int n;
    cin>>n;
    ll ar[n];
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);
    cout<<"Case #"<<tc<<": ";
    if(n!=5){
        double st = ar[0]+(ar[1]-ar[0])/2.0;
        double en = ar[n-2]+ (ar[n-1]-ar[n-2])/2.0;
        cout<<en-st<<endl;
    }
    else {
        double ans  ;
        double st = ar[0]+double(ar[1]-ar[0])/2.0;
        double en = ar[2]+ double(ar[4]-ar[2])/2.0;
        ans = en -st;
        st = ar[0]+double(ar[2]-ar[0])/2.0;
        en = ar[3]+ double(ar[4]-ar[3])/2.0;
        ans = max(ans, en-st);
        cout<<fixed<<setprecision(7)<<ans<<endl;

    }

}
    

int main()
{
    fastio;
    int t = 1;
    //file();
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}