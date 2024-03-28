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
    string s;
    cin>>s;
    int n = s.size(), ele = 0, sts = 1;
    bool f = 1;
    for(int i=0 ; i<n ; i++){
        if(s[i]=='+'){
            ele++;
            if(ele<=1) sts = 1;
            if(ele==2) sts = 3; 
        }
        else if(s[i]=='-'){
            ele--;
            if(ele<2)sts = 1;
        }
        else if(s[i]=='1'){
            if(sts == 2){
                f=0;
                break;
            }
            sts = 1;
        }
        else {
            if(sts == 1){
                f=0;
                break;
            }
            sts = 2;
        }
        
    }
    if(f)YES;
    else NO;
}
    

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}