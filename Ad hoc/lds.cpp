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

bool isPerfect(int k){
    set<int>st;
    while(k>0){
        st.insert(k%10);
        k/=10;
    }
    for(auto it: st ){
        if(it != 3 && it != 5){
            return false;
        }
    }
    return true ;
}

vector<int>pr;
void solve(int tc)
{
    int n;
    cin>>n;
    
    for(auto itt : pr){
        if(n%itt == 0){
            cout<<n<<" "<<itt<<endl;
            return ;
        }
            
    }
    cout<<n<<" Nope"<<endl;

}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for(int i=1; i<=4000; i++){
        if(isPerfect(i))pr.push_back(i);
    }
    for (int i = 1; i <= t; i++)
        solve(i);
}