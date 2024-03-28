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

int cnt[1000]; 
void pcs(string &s){
    int sz = s.size(), sum=0;
    for(int i=0; i<sz; i++){
        sum += s[i]-'0'; 
    }
    cnt[sz*100+sum]++;
}

void solve(int tc)
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0 ; i<n; i++){
        cin>>s[i];
        pcs(s[i]);
    }
    ll dbl = 0 ;
    ll res = 0 ;
    for(int i=0; i<n; i++){
        for(int j = 2; j<=10; j+=2){
            if(j<= s[i].size() || s[i].size() < j/2)continue;
                
                ll sum1 = 0,sum2 =0 ;
                int k = 0 ;
                for( ; k<j/2 ; k++)
                    sum1 += s[i][k]-'0';
                
                
                for(; k<s[i].size() ;k++)
                    sum2 += s[i][k]-'0';
                int nedlen = j - s[i].size();
                res += cnt[nedlen*100+(sum1-sum2)];
                if(s[i].size() != j/2){
                    ll sum2=0 , sum3 =0;
                    k = 0;
                    for(k = s[i].size()-1; k>=s[i].size()- (j/2) ; k--){
                        sum2 += s[i][k]-'0';
                    }
                    for(; k>=0 ; k--)sum3 += s[i][k]-'0';

                    res += cnt[nedlen*100+sum2-sum3];
                }

        }
       
    }
    res -= dbl/2;
    cout<<res<<endl; 
}
    

int main()
{
    fastio;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}