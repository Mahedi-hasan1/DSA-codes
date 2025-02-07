#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n, s, m, st =0 , en =0;
        cin>>n>>s>>m;
        long long ans = 0;
        vector<long long>ar(n),br(n);
        for(int i=0 ;i<n; i++){
            cin>>ar[i]>>br[i];
            if(i==0){
                if(ar[i]-0>=s)ans=1;
            }
            
            else{
                if(ar[i]-br[i-1]>=s){
                    ans=1;
                }
            }
        }
        
        if(m-br[n-1]>=s)ans=1;
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
}