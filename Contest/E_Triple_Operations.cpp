#include<bits/stdc++.h>
using namespace std;
const long long mx = 2e5+5;
vector<long long>v(mx);
long long cnt(long long a){
    long long c =0;
    while(a!=0){
        a/=3;
        c++;
    }
    return c;
}
int main(){
    int t;
    cin>>t;
    for(int i=1; i<mx; i++){
        v[i]= cnt(i);
        if(i!=1)v[i]+=v[i-1];
    }
    while(t--){
        long long l, r, ans=0;
        cin>>l>>r;
        
        ans += cnt(l)*2;
        ans+= v[r] - v[l];
        cout<<ans<<endl;

    }
}