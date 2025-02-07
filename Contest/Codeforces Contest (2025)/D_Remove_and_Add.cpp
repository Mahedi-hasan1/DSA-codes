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

bool posWithoutDel(vector<int>&v){
    int len = v.size();
    for(int i=1;i<len ; i++){
        if(v[i]<v[i-1])return 0;
        if(v[i]==v[i-1])v[i]++;
    }
    return 1;
}


void solve(int tc)
{
    int n; 
    cin>>n;
    vector<int>ar(n,0);
    for(int i=0 ; i<n; i++)cin>>ar[i];

    bool res = 0;
    vector<int>maydel,v1,v2;
    for(int i=1 ;i<n; i++){
        if(ar[i]<ar[i-1]){
            maydel.pb(i);
            maydel.pb(i-1);
        }
    }
    if(maydel.size()>2){
        NO;
        return;
    }
    if(maydel.size()>0){
        for(int i=0 ;i<n; i++){
            if(i==maydel[0]){
                v1.pb(ar[i]);
            }
            else if(i==maydel[1]){
                v2.pb(ar[i]);
            }
            else {
                v1.pb(ar[i]);
                v2.pb(ar[i]);
            }
        }
        if(posWithoutDel(v1)){
            YES;
            return;
        }
        if(posWithoutDel(v2)){
            YES;
            return;
        }
    }

    vector<int>perfect(1,0);
    int j=0, nodel =1;
    for(int i=0 ; i<n ; i++){
        if(ar[i]>perfect[j]){
            perfect.pb(ar[i]);
            j++;
        }
        else if(ar[i]==perfect[j]){
            perfect.pb(ar[i]+1);
            j++;
        }
        else if( perfect[j] - ar[i] >= 1 && nodel){
            nodel=0;
        }
    }
    if(perfect.size()>=n)YES;
    else NO;


    
}
    

int main()
{
    //fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}