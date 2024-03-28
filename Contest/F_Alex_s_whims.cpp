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

void change(stack<int>&one, stack<int>&two, int cnt){
    int z = two.top();
    vector<int>v;
    for(int i=0 ; i<cnt; i++){
        int tmp = one.top();
        one.pop();
        v.push_back(tmp);
    }
    for(int i=v.size()-1; i>=0 ; i--)two.push(v[i]);
    int x = v[v.size()-1], y = one.top();
    cout<<x<<" "<<y<<" "<<z<<endl;

}

void solve(int tc)
{
    int n, d;
    cin>>n>>d;
    stack<int>one,two;
    two.push(2);
    for(int i =0,a =1, b=2 ; i<n-1 ; i++){
        cout<<a++<<" "<<b++<<endl;
        one.push(i+1);
    }
    one.push(n);
    int s = 0, p = n-1;

    while(d--){
        cin>>s;
        if(s==p){
            cout<<"-1 -1 -1"<<endl;
            continue;
        }
        if(s<p)change(one, two, p-s);
        else change(two , one, s-p);
        p = s;
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