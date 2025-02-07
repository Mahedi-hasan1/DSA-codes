#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b, c,d ;
        cin>>a>>b>>c>>d;
        int ans =0 ;
        if(a>c && b>d)ans++;
        if(b>c && a>d)ans++;
        if(a>d && b>c)ans++;
        if(b>d && a>c)ans++;

        if(a==c && b>d)ans++;
        if(b==c && a>d)ans++;
        if(a==d && b>c)ans++;
        if(b==d && a>c)ans++;

        if(a>c && b==d)ans++;
        if(b>c && a==d)ans++;
        if(a>d && b==c)ans++;
        if(b>d && a==c)ans++;
        
        cout<<ans<<endl;

    }
}