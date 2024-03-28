#include<bits/stdc++.h>
#include <string>
#define inf  1e9+7
using namespace std;


map<pair<int,int>, int>visited;


int remainder(int a, int b){
    int ans = a%b;
    if(ans<0)ans+=b;
    return ans;
}


int ArrayChallenge(vector<int>arr, int arrLength) {
  
   
  int mx = -inf, mxPosition=0;
    
  for(int i=0 ;i<arrLength; i++){

    if(arr[i]>mx){
        mx = arr[i];
        mxPosition = i;
    }
  }
  queue<pair<int,int>>que; // make unique by adding indivitual index
  int steps = 0 , result = -1;
  bool resultFound = 0 ;
  for(int i=0 ; i<arrLength; i++){
    if(remainder(i+arr[i], arrLength) == mxPosition){
        que.push({arr[i],i});
        visited[{arr[i],i}]=1;
    }
    else if(remainder(i-arr[i], arrLength) == mxPosition){
        que.push({arr[i],i});
        visited[{arr[i],i}]=1;
    }
  }
  steps++;

  while(!que.empty()){
    vector<pair<int,int>>current;

    while(!que.empty()){
        cout<<que.front().first<<que.front().second<<" ";
        current.push_back(que.front());
        que.pop();
    }
    cout<<endl;
    int currLength = current.size();
    for(int i=0 ; i<currLength; i++){
        if(current[i].second == mxPosition){
            result = steps;
            resultFound = 1;
            break; 
        }
        for(int j=0 ; j<arrLength; j++){
            if(visited[{arr[j], j}])continue;
            if(remainder(j+arr[j], arrLength) == current[i].second){
                que.push({arr[j],j});
                visited[{arr[j],j}]=1;
            }
            else if(remainder(j-arr[j], arrLength) == current[i].second){
                que.push({arr[j],j});
                visited[{arr[j],j}]=1;
            }
        }
        
    }
    if(resultFound)break;
    steps++;
  }

  return result;

}

int main(void) { 
   
  // keep this function call here
  int n;
  cin>>n;
  vector<int>A(n);
  for(int i=0 ;i<n; i++)cin>>A[i];

  
  cout << ArrayChallenge(A, n);
  return 0;
    
}