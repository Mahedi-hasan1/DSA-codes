#include <bits/stdc++.h>
using namespace std;

void ShirtDistribution(int NumberOfShirts, int NumberOfBags ){
    int sizeOfBag = NumberOfShirts/NumberOfBags;

    if(NumberOfShirts % NumberOfBags > NumberOfBags/2){
        sizeOfBag++;
    }

    int SizeOfDifferentBag = NumberOfShirts - ( sizeOfBag * (NumberOfBags-1));

    cout<<"Size of same Bags "<<sizeOfBag<<endl;

    cout<<"Size of different one "<<SizeOfDifferentBag<<endl;

}

void solve(int tc)
{
    int NumberOfShirts, NumberOfBags;
    
    cin>>NumberOfShirts>>NumberOfBags;
    ShirtDistribution(NumberOfShirts, NumberOfBags);

}
    

int main()
{
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; i++)
        solve(i);
}