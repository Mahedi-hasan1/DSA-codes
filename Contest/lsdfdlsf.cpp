#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b, c,d ;
        cin>>a>>b>>c>>d;
        int boro=0;
        if(a>b)swap(a,b);
        if(a>c &&  a>d && b>c && b>d)cout<<4<<endl;
        else if(b>c && b>d && (a>c || a>d))cout<<2<<endl;

    }
}