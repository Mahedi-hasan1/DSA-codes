#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        int n = s.size(),j=0;
        for(int i=0 ; i<n; i++){
            if(s[i]==t[j]){
                j++;
                if(j==t.size()) break;
            }
            else if(s[i]=='?'){
                s[i]=t[j];
                j++;
                if(j==t.size()) break;
            }
        }
        if(j < t.size())cout<<"NO"<<endl;
        else {
            for(int i=0 ; i<n; i++)
                if(s[i]=='?')s[i]='a';
            cout<<"YES"<<endl<<s<<endl;
        }

    }
}