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

vector<int>v;

int isper(int x){
    set<int>st;
    while(x>0){
        st.insert(x%10);
        x /= 10;
    }
    if(auto it : st){
        if(it != 5 || it != 3) return false;
    }
    return true;
}

void solve(int tc)
{
    for(int i=1; i<=4000 ; i++){
        if(isper(i))v.pb(i);
    }
}
int cnt =0 ;
for(auto it : v){
    int tmp = v;
    while(tmp>0 && tmp % it ==0){
        cnt++;
        tmp/=it;
    }
}
cout<<cnt;
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}