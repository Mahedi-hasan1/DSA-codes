#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back

//Solution 1 (abid)

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    a%=b;
    return gcd(b,a);
}
void sol()
{
 
    ll n,m,t,i,j,k,x,y,z,a,b,c,cnt=0,ans=0;
    string s,s1,s2,s3;
    cin>>n>>x>>k;
    ll big=(((n-2)*180)-(n*x));
    ll small=(n*(n-1))/2;
    ll nCr=gcd(big,small);
    big/=nCr;
    small/=nCr;
    ll p=(x*small)+((k-1)*big);
    ll q=small;
    nCr=gcd(p,q);
    p=p/nCr;
    q=q/nCr;
    cout<<p<<" "<<q<<endl;
 
}
int main()
{
    ll tc;
    cin>>tc;
    while(tc--)
        sol();

}

//Solution 2 //avro

ll gcd(ll a , ll b)
{
   if(b==0) return a;
   a%=b;
   return gcd(b,a);
}
 
 
int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, x, k;
        cin >> n >> x >> k;
        ll dUpper = (((n-2)*180)-(n*x));
        ll dLower = (n*(n-1))/2;
        ll dCmn = gcd(dUpper, dLower);
        dUpper = dUpper/dCmn;
        dLower = dLower/dCmn;
        ll u = ((x*dLower) + ((k-1)*dUpper));
        ll d = dLower;
        dCmn = gcd(u, d);
        u = u/dCmn;
        d = d/dCmn;
        cout << u << " " << d << "\n";
    }
    return 0;
}