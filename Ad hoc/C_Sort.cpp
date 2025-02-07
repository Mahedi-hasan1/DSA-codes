#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define rall(x) x.rbegin(), x.rend()
#define all(x) x.begin(), x.end()
#define ff first
#define ss second


void solve(int tc)
{
    int n,q;
    cin>>n>>q;
    string s,p ;
    cin>>s>>p;
    vector<vector<int>>v(n, vector<int>(26,0));
    vector<vector<int>>v2(n, vector<int>(26,0));

    for(int i=0 ;i<n; i++){
        if(i==0){
            v[i][s[i]-'a']=1;
            v2[i][p[i]-'a']=1;
        }
        else {
            v[i][s[i]-'a']= v[i-1][s[i]-'a']+1;
            v2[i][p[i]-'a']=v2[i-1][p[i]-'a']+1;
            for(int j=0 ;j<26;j++){
                v[i][j] = max(v[i-1][j], v[i][j]);
                v2[i][j] = max(v2[i-1][j], v2[i][j]);
            }
        }
    }

    while(q--){
        int l, r;
        cin>>l>>r;
        l--; r--;
        int res = 0 ;
        if(l>0){
            for(int i=0 ; i<26;i++){
                res += abs((v[r][i]-v[l-1][i]) - (v2[r][i] - v2[l-1][i]));
            }
        }
        else {
            for(int i=0 ; i<26 ;i++){
                res += abs(v[r][i] - v2[r][i]);
            }
        }
        cout<<res/2<<endl;
    }

    
}
    

int main()
{
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}