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
    int n, q;
    cin>>n>>q;
    int on =0, tw =0 ;
    int ar[n];
    set<int>ones;
    ll mx =0;
    for(int i=0,a ; i<n; i++){
        cin>>a;
        ar[i]=a;
        if(a&1){
            ones.insert(i);
        }
        mx += a;
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int val;
            cin>>val;
            if(val>mx)NO;
            else if(ones.size() == 0 &&  val%2==0)YES;
            else if(ones.size() ==0 && val%2 == 1)NO;
            else {
                int st = *ones.begin();
                auto it = ones.end();
                it--;
                int en = *it;
                en = n-en-1;
                st= min(st,en);
                int til = mx - (2*st);
                if(val>til && (mx&1) != (val&1))NO;
                else YES; 
            }
        }
        else{
            int pos, val;
            cin>>pos>>val;
            pos--;
            mx -= ar[pos];
            mx += val;

            if(ar[pos]==1)ones.erase(pos);
            if(val==1)ones.insert(pos);
            ar[pos] = val;
        }
    }
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}