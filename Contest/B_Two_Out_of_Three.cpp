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
    int n;
    cin>>n;
    int ar[n];
    for(int i=0 ; i<n; i++){
        cin>>ar[i];
    }
    vector<int>v(n,1);
    int cnt = 0 , tmp = -1;
    for(int i=0 ; i<n; i++){
         for(int j=i+1; j<n; j++){
            if(ar[i]==ar[j] && ar[i] != tmp){
                if(cnt==0){
                    tmp = ar[i]; 
                    v[i]=1;
                    v[j]=2;
                    cnt++;
                    break;
                }
                else {
                    v[i]=1;
                    v[j]=3;
                    cnt++;
                    break;
                }
            }
            
         }
         if(cnt==2)break;
    }
    if(cnt<2)cout<<-1<<endl;
    else {
        for(int i =0 ; i<n; i++)cout<<v[i]<<" ";
        cout<<endl;
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