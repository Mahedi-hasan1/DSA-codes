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

void solve(int tc)
{
    int n;
    cin >> n;
    int bt[n][40], ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    memset(bt, 0, sizeof bt);
    for (int i = n - 1; i >= 0; i--)
    {
        int j =0 , tmp = ar[i];
        while (tmp > 0)
        {
            bt[i][j] = (tmp & 1);
            tmp /= 2;
            j++;
        }
    }
    // for (int i = 0; i <n; i++)
    // {
    //     for(int j =0;j<5 ;j++){
    //         cout<<bt[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    for (int i = n - 1; i >= 0; i--)
    {
        for(int j =0;j<40 ;j++){
            if(i==n-1){
                if(bt[i][j]==0)bt[i][j]=-1;
                else bt[i][j] = i;
            }
            else{
                if(bt[i][j]==0)bt[i][j]=-1;
                else {
                    if(bt[i+1][j] == -1) bt[i][j]= i;
                    else bt[i][j]= bt[i+1][j];
                }
            }
        }
    }
    // for (int i = 0; i <n; i++)
    // {
    //     for(int j =0;j<5 ;j++){
    //         cout<<bt[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int q;
    cin>>q;
    while(q--){
        ll l ,k;
        cin>>l>>k;
        int tmp = k;
        ll dig = 0;
        int kr[40],j =0;
        while(tmp>0){
            dig ++ ;
            kr[j]= (tmp&1);
            j++;
            tmp/=2;
        }
        
        int res = INT_MAX, tmx=-1;
        for(int i=dig-1 ; i>=0 ; i--){
            if(kr[i]==0){
                tmx = max(tmx , bt[l-1][i]);
            }
            else {
                tmp = bt[l-1][i];
                tmp = max(tmp, tmx);
                res = min(res, tmp);
            }
        }


        for(int i = dig ; i<40 ; i++){
            if(bt[l-1][i] != -1)res = max(res, bt[l-1][i]);
        }
        if(res != -1)cout<<res+1<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
}

int main()
{
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}